// player.cpp
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "table.hpp"
#include "bet.hpp"

Player::Player(const std::string& n, int startMoney) :
    name(n),
    money(startMoney),
    playerType("generic")
{
    bets = new std::vector<Bet *>;
}

Player::~Player()
{
    bets->clear();
    delete bets;
}

std::string Player::toString() const
{
    return getPlayerType() + " player " + name + " has $" + std::to_string(money);
}

std::string Player::getPlayerType() const
{
    return playerType;
}

void Player::makeBets()
{
    std::cout << name << " makes bets" << std::endl;
}

void Player::payPlayer(int amount)
{
    money += amount;
}

// =====================================================================================

PassLinePlayer::PassLinePlayer(const std::string& n, int startMoney) : Player(n, startMoney) {}

std::string PassLinePlayer::getPlayerType() const
{
    return "Pass Line";
}

void PassLinePlayer::makeBets()
{
    std::cout << name << " makes Pass Line bet" << std::endl;
    //table->addBet(new PassLineBet(table, this, 5));
}

// =====================================================================================

FieldPlayer::FieldPlayer(const std::string& n, int startMoney) : Player(n, startMoney) {}

std::string FieldPlayer::getPlayerType() const
{
    return "Field";
}

void FieldPlayer::makeBets()
{
    std::cout << name << " makes Field bet" << std::endl;
    //table->addBet(new FieldBet(table, this, 5));
}

// =====================================================================================
