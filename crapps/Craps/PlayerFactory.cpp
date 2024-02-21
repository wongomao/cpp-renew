#include <sstream>
#include <vector>
#include "PlayerFactory.h"
#include "easylogging++.h"

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
	if (!config.config_obj.contains("PLAYERS"))
	{
		return;
	}
	auto players_obj = config.config_obj["PLAYERS"];
	if (players_obj.is_array())
	{
		for (auto jplayer : players_obj)
		{
			if (jplayer.is_object() && jplayer.contains("TYPE"))
			{
				std::string type = jplayer["TYPE"];
				Player* p = nullptr;
				if (type == "FIELD")
				{
					p = create_field_player(jplayer);
				}
				else if (type == "PASS")
				{
					p = create_pass_player(jplayer);
				}
				else if (type == "ODDS")
				{
					p = create_odds_player(jplayer);
				}
				else if (type == "PLACE")
				{
					p = create_place_player(jplayer);
				}
				if (p != nullptr)
				{
					players->push_back(p);
					table->add_player(p);
				}
			}
		}
	}
}

FieldPlayer* PlayerFactory::create_field_player(json jplayer)
{
	try
	{
		std::string name = jplayer["NAME"];
		int start_bank = jplayer["START_BANK"];
		int base_bet = jplayer["BASE_BET"];
		return new FieldPlayer(name, start_bank, base_bet);
	}
	catch (const std::exception&)
	{
		LOG(ERROR) << "Error reading configuration file for field player";
	}
	return nullptr;
}

PassPlayer* PlayerFactory::create_pass_player(json jplayer)
{
	try
	{
		std::string name = jplayer["NAME"];
		int start_bank = jplayer["START_BANK"];
		int base_bet = jplayer["BASE_BET"];
		return new PassPlayer(name, start_bank, base_bet);
	}
	catch (const std::exception& e)
	{
		LOG(ERROR) << "Error reading configuration file for pass player: " << e.what();
	}
	return nullptr;
}


OddsPlayer* PlayerFactory::create_odds_player(json jplayer)
{
	try
	{
		std::string name = jplayer["NAME"];
		int start_bank = jplayer["START_BANK"];
		int base_bet = jplayer["BASE_BET"];
		int odds_multiplier = jplayer["ODDS_MULTIPLIER"];
		return new OddsPlayer(name, start_bank, base_bet, base_bet * odds_multiplier);
	}
	catch (const std::exception& e)
	{
		LOG(ERROR) << "Error reading configuration file for odds player: " << e.what();
	}
	return nullptr;
}


PlacePlayer* PlayerFactory::create_place_player(json jplayer)
{
	try
	{
		std::string name = jplayer["NAME"];
		int start_bank = jplayer["START_BANK"];
		auto place_numbers = jplayer["PLACE_NUMBERS"];
		auto pp = new PlacePlayer(name, start_bank);
		for (auto n : place_numbers)
		{
			int place_number = n.get<int>();
			int bet_amount = 0;
			if (place_number == 4 || place_number == 10)
			{
				bet_amount = jplayer["BASE410_BET"];
			}
			else if (place_number == 5 || place_number == 9)
			{
				bet_amount = jplayer["BASE59_BET"];
			}
			else if (place_number == 6 || place_number == 8)
			{
				bet_amount = jplayer["BASE68_BET"];
			}
			pp->add_place_number(place_number, bet_amount);
		}
		return pp;
	}
	catch (const std::exception&)
	{
		LOG(ERROR) << "Error reading configuration file for place player";
	}
	return nullptr;
}
