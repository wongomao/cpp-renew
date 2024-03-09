#pragma once
#include <list>
#include <utility>
#include "Player.h"
#include "PlaceBet.h"
#include "HardwaysBet.h"
#include "PassOddsBet.h"

class ClassicPlayer : public Player
{
public:
	std::list<std::pair<int, int>> *place_numbers;
	std::list<std::pair<int, int>> *hardway_numbers;
	int pass_bet_amount;
	int odds_bet_multiplier;

	ClassicPlayer(const std::string& name, int start_money);
	~ClassicPlayer();
	virtual std::string get_player_type() const override;
	void add_place_number(int place_number, int bet_amount);
	void add_hardway_number(int hardway_number, int bet_amount);
	void make_bets() override;
};

