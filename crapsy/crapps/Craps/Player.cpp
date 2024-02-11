#include <string>
#include <list>
#include "Player.h"
#include "Table.h"
#include "Bet.h"
#include "easylogging++.h"

class Table;
class Bet;

Player::Player(const std::string& name, int start_money, int base_bet)
	: name(name), money(start_money), base_bet(base_bet), table(nullptr), bets(nullptr),
	log_player(false), lowest_money(start_money), highest_money(start_money)
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
		+ " has $" + std::to_string(money)
		+ " Hi: $" + std::to_string(highest_money) + " Lo: $" + std::to_string(lowest_money);
	return s;
}

void Player::set_table(Table* t)
{
	table = t;
}

void Player::track_money()
{
	// keep track of highest and lowest money
	if (money < lowest_money)
	{
		lowest_money = money;
	}
	if (money > highest_money)
	{
		highest_money = money;
	}
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
				if (log_player)
				{
					LOG(INFO) << "\t" << name << " reactivates Pass Line bet";
				}
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
		if (log_player)
		{
			LOG(INFO) << "\t" << name << " makes Pass Line bet of $" << base_bet;
		}
    }
	track_money(); // keep track of highest and lowest money
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
				if (log_player)
				{
					LOG(INFO) << "\t" << name << " reactivates Field bet";
				}
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
		if (log_player)
		{
			LOG(INFO) << "\t" << name << " makes Field bet of $" << base_bet;
		}
	}
	track_money(); // keep track of highest and lowest money
}