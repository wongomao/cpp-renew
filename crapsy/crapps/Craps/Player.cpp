#include <string>
#include <list>
#include "Player.h"
#include "Table.h"
#include "Bet.h"
#include "easylogging++.h"

class Table;
class Bet;

Player::Player(const std::string& name, int start_money, int base_bet)
	: name(name), start_money(start_money), money(start_money),
	base_bet(base_bet), sum_bets(0), sum_wins(0),
	table(nullptr), bets(nullptr),
	lowest_money(start_money), highest_money(start_money)
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
	float hi_percent = (float)highest_money / (float)start_money * 100;
	float lo_percent = (float)lowest_money / (float)start_money * 100;
	if (lowest_money < 0)
	{
		lo_percent -= 100;
	}
	std::string rtpStr = "N/A";
	if (sum_bets != 0)
	{
		float rtp = (float)sum_wins / (float)sum_bets * 100;
		rtpStr = std::to_string(rtp) + "%";
	}
	std::string s = get_player_type()
		+ " player " + name
		+ " has $" + std::to_string(money)
		+ " Hi: $" + std::to_string(highest_money) + " (+" + std::to_string(hi_percent) + "%)"
		+ " Lo: $" + std::to_string(lowest_money) + " (-" + std::to_string(lo_percent) + "%)"
		+ " Bets: $" + std::to_string(sum_bets)
		+ " Wins: $" + std::to_string(sum_wins)
		+ " RTP: " + rtpStr;
	return s;
}

void Player::log_player()
{
	float hi_percent = (float)highest_money / (float)start_money * 100;
	float lo_percent = (float)lowest_money / (float)start_money * 100;
	std::string hilo = std::vformat("Hi: ${} ({%.1f}%) Lo: ${} ({%.1f}%)",
		std::make_format_args(highest_money, hi_percent, lowest_money, lo_percent));
	float rtp = 100 * (float)sum_wins / ((sum_bets != 0) ? (float)sum_bets : 0.000001f);
	LOG(INFO) << get_player_type() << " player " << name
		<< " has $" << money
		<< " " << hilo
		<< " Bets: $" << sum_bets
		<< " Wins: $" << sum_wins
		<< " RTP: " << std::vformat("{%.1f}", std::make_format_args(rtp));
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
	sum_wins += amount;
	money += amount;
}

void Player::subtract_bet_amount(int bet_amount)
{
	sum_bets += bet_amount;
	money -= bet_amount;
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
				subtract_bet_amount(b->amount); // move money to bet, same amount
                b->set_active(true);
                table->accept_bet(b); // hand to table

            }
        }
    }
    else
    {
        // no bets, so make a new one
        // create pass line bet and hand to table
		subtract_bet_amount(base_bet); // move money to bet
        auto bet = new PassBet(this, base_bet);
        table->accept_bet(bet);
        bets->push_back(bet); // add bet to player's list of bets
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
			// there should only be one bet, but just in case
			// always make sure bet is active for each roll
			b->set_active(true);
			// always place new bet from player's money
			subtract_bet_amount(b->amount); // use same amount
			table->accept_bet(b); // hand to table
		}
	}
	else
	{
		// no bets, so make a new one
		subtract_bet_amount(base_bet); // move money to bet
		auto bet = new FieldBet(this, base_bet);
		table->accept_bet(bet);
		bets->push_back(bet); // add bet to player's list of bets
	}
}