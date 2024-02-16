#pragma once
#include "config.h"
#include "Table.h"
#include "Player.h"
#include "OddsPlayer.h"

class PlayerFactory
{
public:
	Config config;
	std::vector<Player *> *players;

	PlayerFactory(Config config);
	~PlayerFactory();
	void add_config_players_to_table(Table* table);
	Player* create_player(std::string player_str);
};

