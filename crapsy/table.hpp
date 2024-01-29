// table.hpp

#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include <random>

// forward declaration
class Player;
enum class BetType;
class Bet;

class Table
{
private:
    int bank;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis; // dis uses gen to generate random numbers
    int die1, die2;
    std::vector<Player *> *players; // pointer to a vector of pointers to Player objects

public:
    // constructor-destructor
    Table();
    ~Table();
    void addPlayer(Player *p);
    void removePlayer(Player *p);
    void showPlayers() const;
    void acceptBets();
    Bet *acceptBet(Player *p, int amount, BetType betType);
    void roll();
    void payTable(int amount);
};

#endif // TABLE_HPP