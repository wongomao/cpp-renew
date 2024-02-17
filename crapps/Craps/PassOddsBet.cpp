#include "PassOddsBet.h"

// odds_amt is the intended amount to play
//  after a point is established
PassOddsBet::PassOddsBet(Player* p, int base_amt, int odds_amt)
	: Bet(p, base_amt), odds_amt(odds_amt) {}

std::string PassOddsBet::to_string() const
{
	return "base $" + std::to_string(amount) + " odds $" + std::to_string(odds_amt) + " on Pass Odds";
}

bool PassOddsBet::adjudicate(int die1, int die2, int point)
{
	bool leaveOnTable = true;
	int roll = die1 + die2;
	// point is 0 if come-out roll
	if (point == 0)
	{
		if (roll == 7 || roll == 11)
		{
			// win base
			pay_table(-amount);
			pay_player(amount);
		}
		else if (roll == 2 || roll == 3 || roll == 12)
		{
			// lose, assume odds bet was not made
			pay_table(amount);
			leaveOnTable = false;
		}
		else
		{
			// point is set, odds bet is now active
			// subtract odds from player's money
			player->subtract_bet_amount(odds_amt);
		}
	}
	else
	{
		if (roll == point)
		{
			// win base
			pay_table(-amount);
			pay_player(amount);
			// win odds
			if (roll == 4 || roll == 10)
			{
				pay_table(-odds_amt * 2);
				pay_player(odds_amt * 2);
			}
			else if (roll == 5 || roll == 9)
			{
				pay_table(-odds_amt * 3 / 2);
				pay_player(odds_amt * 3 / 2);
			}
			else if (roll == 6 || roll == 8)
			{
				pay_table(-odds_amt * 6 / 5);
				pay_player(odds_amt * 6 / 5);
			}
			pay_player(odds_amt); // return the odds bet to the player
		}
		else if (roll == 7)
		{
			// lose
			pay_table(amount + odds_amt);
			leaveOnTable = false;
		}
		// ignore all other rolls
	}

	return leaveOnTable;
}