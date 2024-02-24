#pragma once
#include "Player.h"
#include "PlaceBet.h"

class PlaceActivePlayer : public Player
{
public:
	PlaceBet* bet6;
	PlaceBet* bet8;
	bool bets_pulled_until_come_out;
	// This is an 'active' place player, only playing 6 and 8
	// and actively removing bets after they win
	PlaceActivePlayer(const std::string& name, int start_money, int base_bet);
	virtual std::string get_player_type() const override;
	void make_bets() override;
	void bet_won(Bet* bet, int roll, int point) override;
};

