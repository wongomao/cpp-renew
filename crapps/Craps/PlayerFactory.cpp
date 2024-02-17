#include <sstream>
#include <vector>
#include "PlayerFactory.h"

PlayerFactory::PlayerFactory(Config config)
	: config(config), players(new std::vector<Player *>) {}

PlayerFactory::~PlayerFactory()
{
	// clean up players
	for (auto p : *players)
	{
		delete p;
	}
	players->clear();
	delete players;
}

/// <summary>
/// Create the players based on the config map
/// key: PLAYER; value: player_name,player_type,startbank,basebet,odds_multiplier
/// </summary>
void PlayerFactory::add_config_players_to_table(Table* table)
{
	// cycle through config map looking for players
	for (auto& kv : config.mmap)
	{
		if (kv.first == "PLAYER")
		{
			if (kv.second != "")
			{
				Player* p = create_player(kv.second);
				if (p != nullptr)
				{
					players->push_back(p);
					table->add_player(p);
				}
			}
		}
	}
}

/// <summary>
/// Given a comma-separated string, create a player object
/// "player_name,player_type,start_bank,base_bet,odds_multiplier"
/// </summary>
/// <param name="player_str"></param>
/// <returns>pointer to Player object</returns>
Player* PlayerFactory::create_player(std::string player_str)
{
	std::string player_name;
	std::string player_type;
	int start_bank(0);
	int base_bet(0);
	int odds_multiplier(0);

	// split the string by comma
	std::istringstream ss(player_str);
	std::string value;
	int i = 0;
	while (std::getline(ss, value, ','))
	{
		if (i == 0)
		{
			player_name = value;
		}
		else if (i == 1)
		{
			player_type = value;
		}
		else if (i == 2)
		{
			start_bank = std::stoi(value);
		}
		else if (i == 3)
		{
			base_bet = std::stoi(value);
		}
		else if (i == 4)
		{
			odds_multiplier = std::stoi(value);
		}
		i++;
	}

	if (player_name != "" && player_type != "" && base_bet > 0)
	{
		if (player_type == "ODDS")
		{
			return new OddsPlayer(player_name, start_bank, base_bet, odds_multiplier * base_bet);
		}
		else if (player_type == "FIELD")
		{
			return new FieldPlayer(player_name, start_bank, base_bet);
		}
		else if (player_type == "PASS")
		{
			return new PassPlayer(player_name, start_bank, base_bet);
		}
	}

	return nullptr;
}
