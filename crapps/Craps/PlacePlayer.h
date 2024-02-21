#pragma once
#include <list>
#include <utility> // https://en.cppreference.com/w/cpp/utility/pair
#include "Player.h"
#include "PlaceBet.h"

class PlacePlayer : public Player
{
public:
	// list of place numbers and their bets
	std::list<std::pair<int,int>> *place_numbers;

	// place player does not use a base bet, so it is set to 0
	PlacePlayer(const std::string& name, int start_money);
	~PlacePlayer();
	virtual std::string get_player_type() const override;
	void add_place_number(int place_number, int bet_amount);
	void make_bets() override;
};
