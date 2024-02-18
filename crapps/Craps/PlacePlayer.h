#pragma once
#include "Player.h"
#include "PlaceBet.h"

class PlacePlayer : public Player
{
public:
	int place_number;
	PlacePlayer(const std::string& name, int start_money, int base_bet, int place_number);
	virtual std::string get_player_type() const override;
	void make_bets() override;
};

