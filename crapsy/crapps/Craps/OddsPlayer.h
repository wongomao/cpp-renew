#pragma once
#include "Player.h"
class OddsPlayer :
    virtual public Player
{
public:
	int odds_bet;
    OddsPlayer(const std::string& name, int start_money, int base_bet, int odds_bet);
	// virtual ~OddsPlayer();

	virtual std::string get_player_type() const override;
	void make_bets() override;
};

