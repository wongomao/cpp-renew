#pragma once
#include "Bet.h"
#include "Player.h"

class HardwaysBet : virtual public Bet
{
public:
	int hardway_number;
	HardwaysBet(Player* p, int amount, int hardway_number);
	std::string to_string() const override;
	bool adjudicate(int die1, int die2, int point) override;
};

