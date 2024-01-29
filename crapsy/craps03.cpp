#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include "table.hpp"
#include "player.hpp"
#include "bet.hpp"

// =====================================================================================


int main()
{
    Table *table = new Table();

    PassLinePlayer *player1 = new PassLinePlayer("John", 1000);
    table->addPlayer(player1);

    FieldPlayer *player2 = new FieldPlayer("Jane", 2000);
    table->addPlayer(player2);

    table->acceptBets();
    table->roll();
    //table->adjudicateBets();

    // table->roll();
    // table->showPlayers();
    // table->removePlayer(player1);
    // table->showPlayers();
    // table->removePlayer(player2);

    return 0;
}