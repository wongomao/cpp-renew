#include "PlacePlayer.h"
#include "table.h"

PlacePlayer::PlacePlayer(const std::string& name, int start_money)
	: Player(name, start_money, 0),
	place_numbers(new std::list<std::pair<int,int>>()) {}

PlacePlayer::~PlacePlayer()
{
	// do not need to free for each pair, scope ends when list is deleted
	delete place_numbers;
	place_numbers = nullptr;
}

std::string PlacePlayer::get_player_type() const
{
	return "Place";
}

void PlacePlayer::add_place_number(int place_number, int bet_amount)
{
	// add a place number + bet amount to the list
	std::pair p = std::make_pair(place_number, bet_amount);
	place_numbers->push_back(p);
}

void PlacePlayer::make_bets()
{
	// make one bet on each place number
	if (bets->size() > 0)
	{
		for (auto b : *bets)
		{
			if (!b->get_active())
			{
				// reactivate bet, whether it won or lost
				subtract_bet_amount(b->amount);
				b->set_active(true);
				table->accept_bet(b);
			}
		}
	}
	else
	{
		// make a new bet
		for (auto place_number_pair : *place_numbers)
		{
			int place_number = place_number_pair.first;
			int bet_amount = place_number_pair.second;
			subtract_bet_amount(bet_amount);

			auto bet = new PlaceBet(this, bet_amount, place_number);
			// off_on_come_out is normally false, but a place bet can be made on the come out roll
			bet->off_on_come_out = true; // each player can set this for each place bet
			// add off_on_come_out to config?
			bets->push_back(bet); // add to my list of bets
			table->accept_bet(bet); // hand to table
		}
	}
}