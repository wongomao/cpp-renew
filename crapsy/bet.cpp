// bet.cpp
#include <iostream>
#include "table.hpp"
#include "player.hpp"
#include "bet.hpp"

Bet::Bet(Player *p, int amt, const BetType betType) :
    player(p),
    amount(amt),
    betType(betType)
{
    table = nullptr;
    status = BetStatus::On;
    active = true;
}

std::string Bet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on UNKNOWN";
}

void Bet::setTable(Table *t)
{
    table = t;
}

void Bet::setStatus(BetStatus s)
{
    status = s;
}

BetStatus Bet::getStatus() const
{
    return status;
}

void Bet::setActive(bool a)
{
    active = a;
}

bool Bet::getActive() const
{
    return active;
}

bool Bet::adjudicate(int die1, int die2, int point)
{
    std::cout << "Adjudicating generic bet: " << toString() << std::endl;
    return true;
}

void Bet::payTable(int amount)
{
    if (table != nullptr)
    {
        table->payTable(amount);
    }
}

void Bet::payPlayer(int amount)
{
    if (player != nullptr)
    {
        player->payPlayer(amount);
    }
}

// =====================================================================================

PassBet::PassBet(Player *p, int amt) : Bet(p, amt, BetType::Pass) {}

std::string PassBet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on Pass Line";
}

bool PassBet::adjudicate(int die1, int die2, int point)
{
    bool leaveOnTable = true;
    // point is 0 if it is the come-out roll
    if (point == 0)
    {
        if (die1 + die2 == 7 || die1 + die2 == 11)
        {
            payPlayer(amount);
        }
        else if (die1 + die2 == 2 || die1 + die2 == 3 || die1 + die2 == 12)
        {
            payTable(amount);
            leaveOnTable = false; // mark the bet to be removed from the table
        }
    }
    else
    {
        if (die1 + die2 == point)
        {
            payPlayer(amount);
        }
        else if (die1 + die2 == 7)
        {
            payTable(amount);
            leaveOnTable = false; // mark the bet to be removed from the table
        }
    }
    return leaveOnTable;
}

// =====================================================================================

FieldBet::FieldBet(Player *p, int amt) : Bet(p, amt, BetType::Field) {}

std::string FieldBet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on Field";
}

bool FieldBet::adjudicate(int die1, int die2, int point)
{
    bool leaveOnTable = true;
    int rollValue = die1 + die2;
    if (rollValue == 2 || rollValue == 12)
    {
        payPlayer(amount * 2);
    }
    else if (rollValue == 3 || rollValue == 4 || rollValue == 9 || rollValue == 10 || rollValue == 11)
    {
        payPlayer(amount);
    }
    else
    {
        payTable(amount);
        leaveOnTable = false; // mark the bet to be removed from the table
    }
    return leaveOnTable;
}

// =====================================================================================
