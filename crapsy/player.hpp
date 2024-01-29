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
    std::string playerType;
    Table *table;
    std::vector<Bet *> *bets;
    // note that each bet is not owned by the player, but by the table
    // and a bet can be nullptr in this list

    Player(const std::string& n, int startMoney);
    ~Player();
    std::string toString() const;
    virtual std::string getPlayerType() const;
    virtual void makeBets();
    void payPlayer(int amount);
};

// =====================================================================================

class PassLinePlayer : virtual public Player
{
public:
    PassLinePlayer(const std::string& n, int startMoney);
    std::string getPlayerType() const;
    void makeBets() override;
};

// =====================================================================================

class FieldPlayer : virtual public Player
{
public:
    FieldPlayer(const std::string& n, int startMoney);
    std::string getPlayerType() const;
    void makeBets() override;
};

// =====================================================================================

#endif // PLAYER_HPP