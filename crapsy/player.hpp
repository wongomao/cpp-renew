// player.hpp

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Table;
class Bet;

// =====================================================================================

class Player
{
private:
public:
    std::string name;
    int money;
    int baseBetAmount;
    Table *table;
    std::list<Bet *> *bets;
    // player owns the bets

    Player(const std::string& n, int startMoney, int baseBetAmount);
    virtual ~Player();
    std::string toString() const;
    virtual std::string getPlayerType() const = 0;
    void setTable(Table *t);
    virtual void makeBets() = 0;
    void payPlayer(int amount);
};

// =====================================================================================

class PassLinePlayer : public Player
{
public:
    PassLinePlayer(const std::string& n, int startMoney, int baseBetAmount);
    // ~PassLinePlayer(); // destructor is not needed
    std::string getPlayerType() const override;
    void makeBets() override;
};

// =====================================================================================

class FieldPlayer : public Player
{
public:
    FieldPlayer(const std::string& n, int startMoney, int baseBetAmount);
    // ~FieldPlayer(); // destructor is not needed
    std::string getPlayerType() const override;
    void makeBets() override;
};

// =====================================================================================

#endif // PLAYER_HPP