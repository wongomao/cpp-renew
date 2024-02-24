#include "PlaceActivePlayer.h"
#include "table.h"

PlaceActivePlayer::PlaceActivePlayer(const std::string& name, int start_money, int base_bet)
	: Player(name, start_money, base_bet),
	bet6(nullptr), bet8(nullptr),
	bets_pulled_until_come_out(false) {}

std::string PlaceActivePlayer::get_player_type() const
{
	return "Place Active";
}

void PlaceActivePlayer::make_bets()
{
	// make one bet on each of 6 and 8, OFF on come-out
	// remove both bets after one either wins
	if (bets->size() > 0 && bet6 != nullptr && bet8 != nullptr)
	{
		if (bets_pulled_until_come_out)
		{
			// here the bets are already pulled, so check for come-out roll
			if (table->get_point() == 0)
			{
				// come-out roll, so place the bets again
				bets_pulled_until_come_out = false;
				subtract_bet_amount(base_bet * 2); // for 6 and 8
				// place bet on 6
				bet6->set_active(true);
				table->accept_bet(bet6);
				// place bet on 8
				bet8->set_active(true);
				table->accept_bet(bet8);
			}
			else
			{
				// point is set, so leave the bets off
			}
		}
		else
		{
			// did bets lose-inactive? if so, reactivate them
			if (!bet6->get_active())
			{
				// reactivate bet6
				subtract_bet_amount(bet6->amount);
				bet6->set_active(true);
				table->accept_bet(bet6);
			}
			if (!bet8->get_active())
			{
				// reactivate bet8
				subtract_bet_amount(bet8->amount);
				bet8->set_active(true);
				table->accept_bet(bet8);
			}
		}
	}
	else
	{
		subtract_bet_amount(base_bet * 2); // for 6 and 8
		// place bet on 6
		bet6 = new PlaceBet(this, base_bet, 6);
		bet6->off_on_come_out = true;
		bets->push_back(bet6); // pushing to list, but not really using list
		table->accept_bet(bet6);
		// place bet on 8
		bet8 = new PlaceBet(this, base_bet, 8);
		bet8->off_on_come_out = true;
		bets->push_back(bet8); // pushing to list, but not really using list
		table->accept_bet(bet8);
	}
}

void PlaceActivePlayer::bet_won(Bet* bet, int roll, int point)
{
	// if either bet won, remove both bets until next come-out roll
	if (bet == bet6)
	{
		// the bet6 won and is already inactive so remove bet8
		bet8->set_active(false);
		table->remove_bet(bet8);
		pay_player(bet8->amount);
	}
	else if (bet == bet8)
	{
		// the bet8 won and is already inactive so remove bet6
		bet6->set_active(false);
		table->remove_bet(bet6);
		pay_player(bet6->amount);
	}
	bets_pulled_until_come_out = true;
}