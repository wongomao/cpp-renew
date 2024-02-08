// player.cpp
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "table.hpp"
#include "bet.hpp"
#include "logger.hpp"

Player::Player(const std::string& n, int startMoney) :
    name(n),
    money(startMoney)
{
    bets = new std::vector<Bet *>;
}

Player::~Player()
{
    // std::cout << "Player destructor called" << std::endl;
    bets->clear();
    delete bets;
}

std::string Player::toString() const
{
    return getPlayerType() + " player " + name + " has $" + std::to_string(money);
}

void Player::setTable(Table *t)
{
    table = t;
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

// PassLinePlayer::~PassLinePlayer()
// {
//     std::cout << "PassLinePlayer destructor called" << std::endl;
// }

std::string PassLinePlayer::getPlayerType() const
{
    return "Pass Line";
}

void PassLinePlayer::makeBets()
{
    std::cout << "\t" << name << " makes Pass Line bet" << std::endl;
    std::string msg = name + " makes Pass Line bet";
    Logger::log(msg.c_str());
    // create pass line bet and hand to table
    auto bet = new PassBet(this, 5);
    table->acceptBet(bet);
    bets->push_back(bet); // add bet to player's list of bets; not owned by player
}

// =====================================================================================

FieldPlayer::FieldPlayer(const std::string& n, int startMoney) : Player(n, startMoney) {}

// FieldPlayer::~FieldPlayer()
// {
//     std::cout << "FieldPlayer destructor called" << std::endl;

// }

std::string FieldPlayer::getPlayerType() const
{
    return "Field";
}

void FieldPlayer::makeBets()
{
    std::cout << "\t" << name << " makes Field bet" << std::endl;
    auto bet = new FieldBet(this, 5);
    table->acceptBet(bet);
    bets->push_back(bet); // add bet to player's list of bets
}

// =====================================================================================
