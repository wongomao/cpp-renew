// bet.hpp

#ifndef BET_HPP
#define BET_HPP

#include <string>

// forward declarations
class Table;
class Player;

enum class BetType
{
    Pass,
    Field
};

class Bet
{
private:
public:
    Table *table;
    Player *player;
    int amount;
    BetType betType;

    Bet(Table *t, Player *p, int amt, BetType type);
    virtual std::string toString() const;
    virtual void adjudicate(int die1, int die2, bool isComeOut, int point);
    void addToTable(int amount);
    void payPlayer(int amount);
};

// =====================================================================================

class PassBet : virtual public Bet
{
public:
    PassBet(Table *t, Player *p, int amt);
    std::string toString() const override;
};

// =====================================================================================

class FieldBet : virtual public Bet
{
public:
    FieldBet(Table *t, Player *p, int amt);
    std::string toString() const override;
};

#endif // BET_HPP