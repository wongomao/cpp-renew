#include "table.hpp"
#include "player.hpp"
#include "bet.hpp"
#include "logger.hpp"

// =====================================================================================

#define ITERATIONS 2

int main()
{
    Logger::log(Level::INFO, "----- Craps game starts -----");

    Table *table = new Table();
    table->setUsingPreroll(true);

    PassLinePlayer *player1 = new PassLinePlayer("John", 1000, 5);
    table->addPlayer(player1);

    FieldPlayer *player2 = new FieldPlayer("Jane", 2000, 5);
    table->addPlayer(player2);

    for (int i = 0; i < ITERATIONS; i++)
    {
        table->acceptBets();
        table->roll();
        table->logBets(); // ---------------------
    }

    table->logPlayers(); // ---------------------

    delete player2;
    delete player1;
    delete table;

    return 0;
}