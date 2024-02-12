// Craps.cpp

#include "Table.h"
#include "Player.h"
#include "OddsPlayer.h"
#include "easylogging++.h"
#include "Config.h"

INITIALIZE_EASYLOGGINGPP

#define MIN_ITERATIONS 10
#define PATH_TO_LOGGER_CONF "C:\\dv\\cpp\\cpp-renew\\crapsy\\crapps\\Craps\\logger.conf"



int main()
{
	// logger configuration
	el::Configurations conf(PATH_TO_LOGGER_CONF);
	el::Loggers::reconfigureLogger("default", conf);
	// craps configuration
	Config config;
	config.start_config();

	Table* table = new Table(config);

	// PassPlayer* pass_player = new PassPlayer("Norman", 1000, 5);
	OddsPlayer* odds_player = new OddsPlayer("Norman", 1000, 5, 10);
	FieldPlayer* field_player = new FieldPlayer("Tracy", 1000, 5);

	table->add_player(odds_player);
	table->add_player(field_player);

	table->play();

	table->log_players();
	table->log_bets();
	table->log_bank();

	// clean up
	delete odds_player;
	delete field_player;
	delete table;
	return 0;
}
