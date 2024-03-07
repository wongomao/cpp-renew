#include "HardwayPlayer.h"
#include "HardwaysBet.h"
#include "Table.h"

HardwayPlayer::HardwayPlayer(const std::string& name, int start_money)
	: Player(name, start_money, 0),
	hardway_numbers(new std::list<std::pair<int, int>>())
{}

HardwayPlayer::~HardwayPlayer()
{
	delete hardway_numbers;
	hardway_numbers = nullptr;
}

std::string HardwayPlayer::get_player_type() const
{
	return "Hardway";
}

void HardwayPlayer::add_hardway_number(int hardway_number, int bet_amount)
{
	// add a hardway number + bet amount to the list
	std::pair p = std::make_pair(hardway_number, bet_amount);
	hardway_numbers->push_back(p);
}

void HardwayPlayer::make_bets()
{
	// make one bet on each hardway number
	if (bets->size() > 0)
	{
		for (auto b : *bets)
		{
			if (!b->get_active())
			{
				// reactivate bet
				subtract_bet_amount(b->amount);
				b->set_active(true);
				table->accept_bet(b);
			}
		}
	}
	else
	{
		// make new bets
		for (auto hardway_number_pair : *hardway_numbers)
		{
			int hardway_number = hardway_number_pair.first;
			int bet_amount = hardway_number_pair.second;
			subtract_bet_amount(bet_amount);

			auto bet = new HardwaysBet(this, bet_amount, hardway_number);
			// off_on_come_out is normally false, but a hardway bet can be made on the come out roll
			bet->off_on_come_out = true; // each player can set this for each hardway bet
			// add off_on_come_out to config?
			bets->push_back(bet); // add to my list of bets
			table->accept_bet(bet); // hand to table
		}
	}
}
