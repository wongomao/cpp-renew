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

enum class BetStatus
{
    On,
    Off
};

class Bet
{
private:
public:
    Table *table;
    Player *player;
    int amount;
    BetType betType;
    BetStatus status;
    bool active;

    Bet(Player *p, int amt, BetType type);
    virtual ~Bet();
    virtual std::string toString() const;
    void setTable(Table *t);
    void setStatus(BetStatus s);
    BetStatus getStatus() const;
    void setActive(bool a);
    bool getActive() const;
    // return true if bet is to stay on the table, false if it is to be removed
    virtual bool adjudicate(int die1, int die2, int point);
    void payTable(int amount);
    void payPlayer(int amount);
};

// =====================================================================================

class PassBet : virtual public Bet
{
public:
    PassBet(Player *p, int amt);
    std::string toString() const override;
    bool adjudicate(int die1, int die2, int point) override;
};

// =====================================================================================

class FieldBet : virtual public Bet
{
public:
    FieldBet(Player *p, int amt);
    std::string toString() const override;
    bool adjudicate(int die1, int die2, int point) override;
};

// =====================================================================================

#endif // BET_HPP