// player.cpp
#include <iostream>
#include <string>
#include <list>
#include "player.hpp"
#include "table.hpp"
#include "bet.hpp"
#include "logger.hpp"

Player::Player(const std::string& n, int startMoney, int baseBetAmount) :
    name(n),
    money(startMoney),
    baseBetAmount(baseBetAmount)
{
    bets = new std::list<Bet *>;
}

Player::~Player()
{
    // std::cout << "Player destructor called" << std::endl;
    bets->clear();
    delete bets;
}

std::string Player::toString() const
{
    std::string playerStr = getPlayerType()
        + " player " + name
        + " has $" + std::to_string(money);
    if (bets->size() > 0)
    {
        std::string s = "\n\t Bets:";
        for (auto b : *bets)
        {
            s += "\n\t\t" + b->toString();
        }
        playerStr += s;
    }
    return playerStr;
}

void Player::setTable(Table *t)
{
    table = t;
}

void Player::payPlayer(int amount)
{
    money += amount;
}

// =====================================================================================

PassLinePlayer::PassLinePlayer(const std::string& n, int startMoney, int baseBetAmount)
    : Player(n, startMoney, baseBetAmount) {}

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
    // pass line player only makes one bet

    // reactivate old bets:
    //  cycle through all bets to see if any are inactive and reactivate them
    //  by subtracting bet amount from player's money
    if (bets->size() > 0)
    {
        for (auto b : *bets)
        {
            if (!b->getActive())
            {
                money -= b->amount; // use same amount
                b->setActive(true);
                table->acceptBet(b); // hand to table
                std::string logMsg = "\t" + name + " reactivates Pass Line bet";
                Logger::log(Level::INFO, logMsg.c_str());
            }
        }
    }
    else
    {
        // no bets, so make a new one
        // create pass line bet and hand to table
        money -= baseBetAmount;
        auto bet = new PassBet(this, baseBetAmount);
        table->acceptBet(bet);
        bets->push_back(bet); // add bet to player's list of bets
        std::string logMsg = "\t" + name + " makes Pass Line bet of $" + std::to_string(baseBetAmount);
        Logger::log(Level::INFO, logMsg.c_str());
    }
}

// =====================================================================================

FieldPlayer::FieldPlayer(const std::string& n, int startMoney, int baseBetAmount) :
    Player(n, startMoney, baseBetAmount) {}

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
    std::string msg = name + " makes bets";
    Logger::log(Level::INFO, msg.c_str());
    // field player only makes one bet
    // reactivate old bet if exists
    if (bets->size() > 0)
    {
        for (auto b : *bets)
        {
            if (!b->getActive())
            {
                money -= b->amount; // use same amount
                b->setActive(true);
                table->acceptBet(b); // hand to table
                std::string logMsg = "\t" + name + " reactivates Field bet";
                Logger::log(Level::INFO, logMsg.c_str());
            }
        }
    }
    else
    {
        // no bets, so make a new one
        money -= baseBetAmount;
        auto bet = new FieldBet(this, baseBetAmount);
        table->acceptBet(bet); // hand to table
        bets->push_back(bet); // add bet to player's list of bets
        std::string logMsg = "\t" + name + " makes Field bet of $" + std::to_string(baseBetAmount);
        Logger::log(Level::INFO, logMsg.c_str());
    }
}

// =====================================================================================
