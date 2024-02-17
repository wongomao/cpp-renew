#include <string>
#include <list>
#include "Player.h"
#include "OddsPlayer.h"
#include "Table.h"
#include "Bet.h"
#include "PassOddsBet.h"
#include "easylogging++.h"

// the odds_bet is the intended amount to be put in play
// if a point is established
// later on we can implement a changeable odds_bet determined by the point
OddsPlayer::OddsPlayer(const std::string& name, int start_money, int base_bet, int odds_bet)
	: Player(name, start_money, base_bet), odds_bet(odds_bet) {}

std::string OddsPlayer::get_player_type() const
{
	return "Odds";
}

void OddsPlayer::make_bets()
{
	// odds player only makes one bet at a time
	// reactivate old bets:
	//  cycle through all bets to see if any are inactive and reactivate them
	//  by subtracting bet amount from player's money
	if (bets->size() > 0)
	{
		for (auto b : *bets)
		{
			if (!b->get_active())
			{
				subtract_bet_amount(b->amount); // subtract bet amount from player's money
				b->set_active(true);
				table->accept_bet(b); // hand bet to table
			}
		}
	}
	else
	{
		subtract_bet_amount(base_bet); // subtract bet amount from player's money
		// the odds bet is not yet subtracted from player's money
		// but will be subtracted when the point is established
		// during an adjudicate() call
		auto bet = new PassOddsBet(this, base_bet, odds_bet);
		table->accept_bet(bet); // add to table's list of bets
		bets->push_back(bet); // add to my list of bets
	}
}