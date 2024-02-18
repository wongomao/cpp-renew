#include "PlacePlayer.h"
#include "table.h"

PlacePlayer::PlacePlayer(const std::string& name, int start_money, int base_bet, int place_number)
	: Player(name, start_money, base_bet), place_number(place_number) {}

std::string PlacePlayer::get_player_type() const
{
	return "Place";
}

void PlacePlayer::make_bets()
{
	if (table->get_point() == 0)
	{
		// no point, so no bets
		return;
	}

	// make one bet on the place number
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
		subtract_bet_amount(base_bet);
		auto bet = new PlaceBet(this, base_bet, place_number);
		table->accept_bet(bet);
		bets->push_back(bet);
	}
}