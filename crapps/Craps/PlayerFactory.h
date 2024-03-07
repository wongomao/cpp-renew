#pragma once
#include "config.h"
#include "Table.h"
#include "Player.h"
#include "OddsPlayer.h"
#include "PlacePlayer.h"
#include "PlaceActivePlayer.h"
#include "HardwayPlayer.h"

class PlayerFactory
{
public:
	Config config;
	std::vector<Player *> *players;

	PlayerFactory(Config config);
	~PlayerFactory();
	void add_config_players_to_table(Table* table);

	FieldPlayer* create_field_player(json jplayer);
	PassPlayer* create_pass_player(json jplayer);
	OddsPlayer* create_odds_player(json jplayer);
	PlacePlayer* create_place_player(json jplayer);
	PlaceActivePlayer* create_place_active_player(json jplayer);
	HardwayPlayer* create_hardway_player(json jplayer);
};

