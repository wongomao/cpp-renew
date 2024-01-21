#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <algorithm>

// =====================================================================================

class Player
{
private:
    int money;
    std::string name;
    std::string playerType;
public:
    Player(const std::string& n, int startMoney) :
        name(n),
        money(startMoney),
        playerType("generic")
        {}
    std::string toString() const
    {
        return getPlayerType() + " player " + name + " has $" + std::to_string(money);
    }
    virtual std::string getPlayerType() const
    {
        return playerType;
    }
    void payPlayer(int amount)
    {
        money += amount;
    }
};

class PassLinePlayer : public Player
{
public:
    PassLinePlayer(const std::string& n, int startMoney) : Player(n, startMoney) {}
    std::string getPlayerType() const override
    {
        return "Pass Line";
    }
};

class FieldPlayer : public Player
{
public:
    FieldPlayer(const std::string& n, int startMoney) : Player(n, startMoney) {}
    std::string getPlayerType() const
    {
        return "Field";
    }
};

// =====================================================================================

class Bet
{
private:
    int amount;
    std::string betType;
    Table *table;
    Player *player;
public:
    Bet(Table *t, Player *p, int amt, const std::string& type) :
        table(t),
        player(p),
        amount(amt),
        betType(type)
        {}
    std::string toString() const
    {
        return player->toString() + " bets $" + std::to_string(amount) + " on " + betType;
    }
    void adjudicate(int die1, int die2, bool isComeOut, int point)
    {
        int roll = die1 + die2;
        std::cout << "Adjudicating bet: " << toString() << std::endl;
        if (isComeOut)
        {
            if (roll == 7 || roll == 11)
            {
                std::cout << "Winner!" << std::endl;
                player->payPlayer(amount);
                amount = 0;
            }
            else if (roll == 2 || roll == 3 || roll == 12)
            {
                std::cout << "Loser!" << std::endl;
                table->payTable(amount);
                amount = 0;
            }
            else
            {
                point = roll;
                std::cout << "Point is " << point << std::endl;
            }
        }
        else
        {
            if (roll == point)
            {
                std::cout << "Winner!" << std::endl;
            }
            else if (roll == 7)
            {
                std::cout << "Loser!" << std::endl;
            }
        }
    }

    void addToTable(int amount)
    {

    }
};

class PassLineBet : public Bet
{
public:
    PassLineBet(Table *t, Player *p, int amt) : Bet(t, p, amt, "Pass Line") {}
};

class FieldBet : public Bet
{
public:
    FieldBet(Table *t, Player *p, int amt) : Bet(t, p, amt, "Field") {}
};

// =====================================================================================

class Table
{
private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis; // dis uses gen to generate random numbers
    int die1, die2;
    std::vector<Player *> *players; // pointer to a vector of pointers to Player objects
    int bank;

public:
    // constructor
    Table() : bank(0), gen(rd()), dis(1, 6) // initialize random number generator
    {
        // initialize players container
        players = new std::vector<Player *>();
        std::cout << "Table constructor called. players: " << players << std::endl;
    }

    // destructor
    ~Table()
    {
        std::cout << "player count: " << players->size() << std::endl;
        std::cout << "Table destructor called" << std::endl;
        delete players;
        players = nullptr;
    }

    void addPlayer(Player *p)
    {
        players->push_back(p);
    }

    void showPlayers() const
    {
        std::cout << "Players:" << std::endl;
        for (auto p : *players)
        {
            std::cout << "\t" << p->toString() << std::endl;
        }
    }

    void removePlayer(Player *p)
    {
        players->erase(std::find(players->begin(), players->end(), p));
    }

    void roll()
    {
        die1 = dis(gen);
        die2 = dis(gen);
        std::cout << "Rolled " << die1 << " and " << die2 << std::endl;
    }

    void payTable(int amount)
    {
        bank += amount;
    }

};

// =====================================================================================

int main()
{
    Table *table = new Table();

    PassLinePlayer *player1 = new PassLinePlayer("John", 1000);
    table->addPlayer(player1);

    FieldPlayer *player2 = new FieldPlayer("Jane", 2000);
    table->addPlayer(player2);

    table->roll();
    table->showPlayers();
    table->removePlayer(player1);
    table->showPlayers();
    table->removePlayer(player2);

    return 0;
}