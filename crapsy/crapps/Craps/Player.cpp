#include <string>
#include <list>
#include "Player.h"
#include "Table.h"
#include "Bet.h"
#include "Logger.h"

class Table;
class Bet;

Player::Player(const std::string& name, int start_money, int base_bet)
	: name(name), money(start_money), base_bet(base_bet), table(nullptr), bets(nullptr)
{
	bets = new std::list<Bet*>;
}

Player::~Player()
{
	for (auto b : *bets)
	{
		delete b;
	}
	delete bets;
	bets = nullptr;
}

std::string Player::to_string() const
{
	std::string s = get_player_type()
		+ " player " + name
		+ " has $" + std::to_string(money);
	return s;
}

void Player::set_table(Table* t)
{
	table = t;
}

void Player::pay_player(int amount)
{
	money += amount;
}

// =================================================================

PassPlayer::PassPlayer(const std::string& name, int start_money, int base_bet)
	: Player(name, start_money, base_bet) {}

std::string PassPlayer::get_player_type() const
{
	return "Pass";
}

void PassPlayer::make_bets()
{
    // pass line player only makes one bet

    // reactivate old bets:
    //  cycle through all bets to see if any are inactive and reactivate them
    //  by subtracting bet amount from player's money
    if (bets->size() > 0)
    {
        for (auto b : *bets)
        {
            if (!b->get_active())
            {
                money -= b->amount; // use same amount
                b->set_active(true);
                table->accept_bet(b); // hand to table
                std::string logMsg = "\t" + name + " reactivates Pass Line bet";
                Logger::log(Level::INFO, logMsg.c_str());
            }
        }
    }
    else
    {
        // no bets, so make a new one
        // create pass line bet and hand to table
        money -= base_bet;
        auto bet = new PassBet(this, base_bet);
        table->accept_bet(bet);
        bets->push_back(bet); // add bet to player's list of bets
        std::string logMsg = "\t" + name + " makes Pass Line bet of $" + std::to_string(base_bet);
        Logger::log(Level::INFO, logMsg.c_str());
    }
}

// =================================================================

FieldPlayer::FieldPlayer(const std::string& name, int start_money, int base_bet)
	: Player(name, start_money, base_bet) {}

std::string FieldPlayer::get_player_type() const
{
	return "Field";
}

void FieldPlayer::make_bets()
{
	// field player makes only one bet

	// reactivate old bets:
	if (bets->size() > 0)
	{
		for (auto b : *bets)
		{
			if (!b->get_active())
			{
				money -= b->amount; // use same amount
				b->set_active(true);
				table->accept_bet(b); // hand to table
				std::string logMsg = "\t" + name + " reactivates Field bet";
				Logger::log(Level::INFO, logMsg.c_str());
			}
		}
	}
	else
	{
		// no bets, so make a new one
		money -= base_bet;
		auto bet = new FieldBet(this, base_bet);
		table->accept_bet(bet);
		bets->push_back(bet); // add bet to player's list of bets
		std::string logMsg = "\t" + name + " makes Field bet of $" + std::to_string(base_bet);
		Logger::log(Level::INFO, logMsg.c_str());
	}
}	