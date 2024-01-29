// bet.cpp
#include <iostream>
#include "table.hpp"
#include "player.hpp"
#include "bet.hpp"

Bet::Bet(Table *t, Player *p, int amt, const BetType betType) :
    table(t),
    player(p),
    amount(amt),
    betType(betType)
    {}

std::string Bet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on UNKNOWN";
}

void Bet::adjudicate(int die1, int die2, bool isComeOut, int point)
{
    std::cout << "Adjudicating bet: " << toString() << std::endl;
}

void Bet::addToTable(int amount)
{
    table->payTable(amount);
}

void Bet::payPlayer(int amount)
{
    player->payPlayer(amount);
}

// =====================================================================================

PassBet::PassBet(Table *t, Player *p, int amt) : Bet(t, p, amt, BetType::Pass) {}

std::string PassBet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on Pass Line";
}

// =====================================================================================

FieldBet::FieldBet(Table *t, Player *p, int amt) : Bet(t, p, amt, BetType::Field) {}

std::string FieldBet::toString() const
{
    return player->toString() + " bets $" + std::to_string(amount) + " on Field";
}

// =====================================================================================
