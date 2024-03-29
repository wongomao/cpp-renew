// Craps.cpp

#include "Table.h"
#include "Player.h"
#include "OddsPlayer.h"
#include "easylogging++.h"
#include "Config.h"
#include "PlayerFactory.h"

INITIALIZE_EASYLOGGINGPP

#define PATH_TO_LOGGER_CONF "C:\\dv\\cpp\\cpp-renew\\crapps\\Craps\\logger.conf"
#define PATH_TO_CRAPS_CONF "C:\\dv\\cpp\\cpp-renew\\crapps\\Craps\\craps_config.json"


int main()
{
	// logger configuration
	el::Configurations conf(PATH_TO_LOGGER_CONF);
	el::Loggers::reconfigureLogger("default", conf);

	// craps configuration
	Config config(PATH_TO_CRAPS_CONF);

	Table* table = new Table(config);
	PlayerFactory* player_factory = new PlayerFactory(config);

	player_factory->add_config_players_to_table(table);
	if (table->have_players())
	{
		table->play();

		table->log_players();
		table->log_bets();
		table->log_bank();
	}
	else
	{
		LOG(ERROR) << "No players found in config file";
	}

	delete player_factory; // cleans up players
	delete table;
	return 0;
}
