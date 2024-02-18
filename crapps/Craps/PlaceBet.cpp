#include "PlaceBet.h"

PlaceBet::PlaceBet(Player* p, int amount, int placed_number)
	: Bet(p, amount), placed_number(placed_number) {}

std::string PlaceBet::to_string() const
{
	return "Place $" + std::to_string(amount) + " on " + std::to_string(placed_number);
}

bool PlaceBet::adjudicate(int die1, int die2, int point)
{
	bool leaveOnTable = false;
	int roll = die1 + die2;
	if (point == 0)
	{
	}
	else
	{
		if (roll == placed_number && (placed_number == 6 || placed_number == 8))
		{
			// player win, pay player 7:6
			pay_table(-amount * 7 / 6);
			pay_player(amount * 7 / 6 + amount);
		}
		else if (roll == placed_number && (placed_number == 9 || placed_number == 5))
		{
			// player win, pay player 7:5
			pay_table(-amount * 7 / 5);
			pay_player(amount * 7 / 5 + amount);
		}
		else if (roll == placed_number && (placed_number == 4 || placed_number == 10))
		{
			// player win, pay player 9:5
			pay_table(-amount * 9 / 5); // take out of table bank
			pay_player(amount * 9 / 5 + amount);
		}
		else if (roll == 7)
		{
			// player lose
			pay_table(amount);
		}
		else
		{
			// leave on table
			leaveOnTable = true;
		}
	}
	return leaveOnTable;
}