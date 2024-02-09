// table.cpp
#include <iostream>
#include <algorithm>
#include "table.hpp"
#include "bet.hpp"
#include "player.hpp"
#include "logger.hpp"

Table::Table() : bank(0), gen(rd()), dis(1, 6) // initialize random number generator
{
    players = new std::list<Player *>(); // initialize players container
    bets = new std::list<Bet *>(); // initialize bets container
    point = 0;
    using_preroll = false;
    preroll = {{1, 1}, {3, 4}, {6, 6}};
    pre_roll_id = 0;
}

// destructor
Table::~Table()
{
    // table does not own the players or the bets
    delete bets; // delete bets list
    bets = nullptr;

    delete players; // delete the vector of pointers to Player objects
    players = nullptr;
}

void Table::setUsingPreroll(bool b)
{
    using_preroll = b;
}

void Table::addPlayer(Player *p)
{
    std::string logMsg = "Adding player: " + p->toString();
    Logger::log(Level::INFO, logMsg.c_str());
    players->push_back(p);
    p->setTable(this);
}

void Table::removePlayer(Player *p)
{
    players->erase(std::find(players->begin(), players->end(), p));
}

void Table::logPlayers() const
{
    std::string logMsg = "Players:";
    for (auto p : *players)
    {
        logMsg += "\n\t" + p->toString();
    }
    Logger::log(Level::INFO, logMsg.c_str());
}

void Table::logBets() const
{
    std::string logMsg = "Bets:";
    for (auto b : *bets)
    {
        logMsg += "\n\t" + b->toString();
    }
    Logger::log(Level::INFO, logMsg.c_str());
}

void Table::acceptBets()
{
    for (auto p : *players)
    {
        p->makeBets();
    }
}

void Table::acceptBet(Bet *b)
{
    if (b != nullptr)
    {
        b->setTable(this);
        bets->push_back(b);
    }
}

// private
void Table::get_preroll()
{
    int roll_id = pre_roll_id++;
    // cycle through 3 different rolls
    int id = roll_id % 3;
    die1 = preroll[id].first;
    die2 = preroll[id].second;
}

void Table::roll()
{
    if (using_preroll)
    {
        get_preroll();
    }
    else
    {
        die1 = dis(gen);
        die2 = dis(gen);
    }
    std::string logMsg = "Rolled " + std::to_string(die1) + " and " + std::to_string(die2);
    Logger::log(Level::INFO, logMsg.c_str());
    adjudicateBets();
    calculateNewPoint();
}

void Table::adjudicateBets()
{
    std::string logMsg = "Adjudicating bets";
    Logger::log(Level::INFO, logMsg.c_str());
    // loop through all bets and adjudicate each one
    for (std::list<Bet *>::iterator it = bets->begin(); it != bets->end();)
    {
        Bet *b = *it; // dereference the iterator to get the pointer to the Bet object
        std::string logMsg = "Adjudicating bet: " + b->toString();
        Logger::log(Level::INFO, logMsg.c_str());
        // adjudicate the bet, pay player or table as needed
        bool leaveOnTable = b->adjudicate(die1, die2, point);
        if (!leaveOnTable)
        {
            b->setActive(false); // set the bet to inactive / taken off the table
            it = bets->erase(it);
            // assuming erase() returns the iterator to the next element
        }
        else
        {
            it++; // move to the next bet
        }
    }
}

// this function is called after the dice are rolled
// to calculate the point for the next roll
void Table::calculateNewPoint()
{
    if (point == 0)
    {
        if (die1 + die2 == 7 || die1 + die2 == 11)
        {
            point = 0;
        }
        else if (die1 + die2 == 2 || die1 + die2 == 3 || die1 + die2 == 12)
        {
            point = 0;
        }
        else
        {
            point = die1 + die2;
        }
    }
    else
    {
        if (die1 + die2 == 7)
        {
            point = 0;
        }
        else if (die1 + die2 == point)
        {
            point = 0;
        }
    }
    std::string logMsg = "New point is " + point;
}

void Table::payTable(int amount)
{
    bank += amount;
}
