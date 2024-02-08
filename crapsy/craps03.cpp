#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include "table.hpp"
#include "player.hpp"
#include "bet.hpp"
#include "logger.hpp"

// =====================================================================================


int main()
{
    Logger::log("Craps game starts");
    Table *table = new Table();

    PassLinePlayer *player1 = new PassLinePlayer("John", 1000);
    table->addPlayer(player1);

    FieldPlayer *player2 = new FieldPlayer("Jane", 2000);
    table->addPlayer(player2);

    table->acceptBets();
    table->showBets();
    table->roll();

    table->showPlayers();
    table->showBets();

    delete player2;
    delete player1;
    delete table;

    return 0;
}