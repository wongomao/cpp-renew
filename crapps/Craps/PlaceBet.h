#pragma once
#include "Bet.h"
#include "Player.h"

class PlaceBet : virtual public Bet
{
public:
	int placed_number;
	PlaceBet(Player* p, int amount, int placed_number);
	std::string to_string() const override;
	bool adjudicate(int die1, int die2, int point) override;
	void tell_player_won(int roll, int point);
};