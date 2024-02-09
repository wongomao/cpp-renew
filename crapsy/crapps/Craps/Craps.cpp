// Craps.cpp

#include "Table.h"
#include "Player.h"
#include "Logger.h"

#define ITERATIONS 10

int main()
{
	Logger::log(Level::INFO, "------ game start -----");

	Table* table = new Table();
	table->set_using_preroll(false);

	PassPlayer* pass_player = new PassPlayer("Norman", 1000, 5);
	FieldPlayer* field_player = new FieldPlayer("Tracy", 1000, 5);

	table->add_player(pass_player);
	table->add_player(field_player);

	for (int i = 0; i < ITERATIONS; i++)
	{
		table->accept_bets();
		table->roll();

		table->log_bets();
	}

	table->log_players();

	// clean up
	delete pass_player;
	delete field_player;
	delete table;
	return 0;
}