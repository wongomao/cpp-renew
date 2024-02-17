#pragma once
#include "Bet.h"
#include "Player.h"
class PassOddsBet :
    virtual public Bet
{
public:
	int odds_amt;
    PassOddsBet(Player* p, int base_amt, int odds_amt);
	std::string to_string() const override;
	bool adjudicate(int die1, int die2, int point) override;
};

