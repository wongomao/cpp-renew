#pragma once
#include "Player.h"
class HardwayPlayer : public Player
{
public:
	// list of hardway numbers and their bets
	std::list<std::pair<int, int>> *hardway_numbers;

	// hardway player does not use a base bet, so it is set to 0
	HardwayPlayer(const std::string& name, int start_money);
	~HardwayPlayer();
	virtual std::string get_player_type() const override;
	void add_hardway_number(int hardway_number, int bet_amount);
	void make_bets() override;
};

