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
    Table *table;
    std::vector<Bet *> *bets;
    // note that each bet is not owned by the player, but by the table
    // and a bet can be nullptr in this list
    // nullptr will indicate that the bet can be removed from the list

    Player(const std::string& n, int startMoney);
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
    PassLinePlayer(const std::string& n, int startMoney);
    // ~PassLinePlayer(); // destructor is not needed
    std::string getPlayerType() const override;
    void makeBets() override;
};

// =====================================================================================

class FieldPlayer : public Player
{
public:
    FieldPlayer(const std::string& n, int startMoney);
    // ~FieldPlayer(); // destructor is not needed
    std::string getPlayerType() const override;
    void makeBets() override;
};

// =====================================================================================

#endif // PLAYER_HPP