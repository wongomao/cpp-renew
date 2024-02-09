#pragma once
#include <random>
#include <list>
#include <vector>

// forward declarations
class Player;
class Bet;
enum class BetType;

class Table
{
private:
	int bank; // only dollars, no cents
	std::random_device rd;
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis;
	int point;

	int die1, die2;
	bool using_preroll;
	std::vector<std::pair<int, int>> preroll;
	int preroll_id;
	
	// Table does not own players or bets
	std::list<Player *> *players;
	std::list<Bet *> *bets;
public:
	// conststructor-destructor
	Table();
	~Table();
	void set_using_preroll(bool b);
	void add_player(Player *p);
	void log_players();
	void log_bets();
	void accept_bets();
	void accept_bet(Bet *b);
	void roll();
	void adjudicate_bets();
	void calculate_new_point();
	void pay_table(int amount);
};

