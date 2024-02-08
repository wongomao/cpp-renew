// table.cpp
#include <iostream>
#include <algorithm>
#include "table.hpp"
#include "bet.hpp"
#include "player.hpp"

Table::Table() : bank(0), gen(rd()), dis(1, 6) // initialize random number generator
{
    players = new std::list<Player *>(); // initialize players container
    bets = new std::list<Bet *>(); // initialize bets container
    point = 0;
    using_preroll = true;
    pre_roll_id = 0;
    std::cout << "Table constructor called; players: " << players << "; bets: " << bets << std::endl;
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

void Table::addPlayer(Player *p)
{
    std::cout << "Adding player: " << p->toString() << std::endl;
    players->push_back(p);
    p->setTable(this);
}

void Table::removePlayer(Player *p)
{
    players->erase(std::find(players->begin(), players->end(), p));
}

void Table::showPlayers() const
{
    std::cout << "Players:" << std::endl;
    for (auto p : *players)
    {
        std::cout << "\t" << p->toString() << std::endl;
    }
}

void Table::showBets() const
{
    std::cout << "Bets:" << std::endl;
    for (auto b : *bets)
    {
        std::cout << "\t" << b->toString() << std::endl;
    }
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
    switch (id)
    {
        case 1:
            die1 = 1;
            die2 = 1;
            break;
        case 2:
            die1 = 3;
            die2 = 4;
            break;
        default:
            die1 = 6;
            die2 = 6;
            break;
    }
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
    std::cout << "Rolled " << die1 << " and " << die2 << std::endl;
    adjudicateBets();
    calculateNewPoint();
}

void Table::adjudicateBets()
{
    // showBets();
    // loop through all bets and adjudicate each one
    for (std::list<Bet *>::iterator it = bets->begin(); it != bets->end();)
    {
        Bet *b = *it; // dereference the iterator to get the pointer to the Bet object
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
    std::cout << "New point is " << point << std::endl;
}

void Table::payTable(int amount)
{
    bank += amount;
}
