#include "HardwaysBet.h"

HardwaysBet::HardwaysBet(Player* p, int amount, int hardway_number)
	: Bet(p, amount), hardway_number(hardway_number) {}

std::string HardwaysBet::to_string() const
{
	return "Hardways $" + std::to_string(amount) + " on " + std::to_string(hardway_number);
}

bool HardwaysBet::adjudicate(int die1, int die2, int point)
{
	bool leaveOnTable = false; // only leave on table if bet is a push
	// if hardways_bet is off_on_come_out, then it is not active on the come out roll
	if (off_on_come_out && point == 0)
	{
		// leave on table
		leaveOnTable = true;
		return leaveOnTable;
	}

	int roll = die1 + die2;
	if (roll == hardway_number)
	{
		if (die1 == die2)
		{
			// win
			if (roll == 4 || roll == 10)
			{
				// player win, pay player 7:1
				pay_table(-amount * 7);
				pay_player(amount * 7 + amount);
			}
			else if (roll == 6 || roll == 8)
			{
				// player win, pay player 9:1
				pay_table(-amount * 9);
				pay_player(amount * 9 + amount);
			}
		}
		else
		{
			// lose
			pay_table(amount);
		}
	}
	else if (roll == 7)
	{
		// player lose
		pay_table(amount);
	}
	else
	{
		// leave on table as push
		leaveOnTable = true;
	}
	return leaveOnTable;
}