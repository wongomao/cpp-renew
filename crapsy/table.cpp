// table.cpp
#include <iostream>
#include <algorithm>
#include "table.hpp"
#include "bet.hpp"
#include "player.hpp"

Table::Table() : bank(0), gen(rd()), dis(1, 6) // initialize random number generator
{
    // initialize players container
    players = new std::vector<Player *>();
    std::cout << "Table constructor called. players: " << players << std::endl;
}

// destructor
Table::~Table()
{
    std::cout << "player count: " << players->size() << std::endl;
    std::cout << "Table destructor called" << std::endl;
    delete players;
    players = nullptr;
}

void Table::addPlayer(Player *p)
{
    players->push_back(p);
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

void Table::acceptBets()
{
    for (auto p : *players)
    {
        p->makeBets();
    }
}

Bet *acceptBet(Player *p, int amount, BetType betType)
{
    return nullptr;
}

void Table::roll()
{
    die1 = dis(gen);
    die2 = dis(gen);
    std::cout << "Rolled " << die1 << " and " << die2 << std::endl;
}

void Table::payTable(int amount)
{
    bank += amount;
}

