// table.hpp

#ifndef TABLE_HPP
#define TABLE_HPP

#include <list>
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
    int point;
    
    int die1, die2;
    bool using_preroll;
    std::vector<std::pair<int, int>> preroll;
    int pre_roll_id;
    void get_preroll(); // preset dice values for testing

    // Table does not own the bets or the players
    std::list<Player *> *players; // pointer to a list of pointers to Player objects
    // using lists for removing bets and players ad hoc
    std::list<Bet *> *bets; // pointer to a list of pointers to Bet objects

public:
    // constructor-destructor
    Table();
    ~Table();
    void setUsingPreroll(bool b);
    void addPlayer(Player *p);
    void removePlayer(Player *p);
    void logPlayers() const;
    void logBets() const;
    void acceptBets();
    void acceptBet(Bet *b);
    void roll();
    void adjudicateBets();
    void calculateNewPoint();
    void payTable(int amount);
};

#endif // TABLE_HPP