#pragma once
#include <string>
#include <list>

class Table;
class Bet;

class Player
{
public:
	std::string name;
	int money;
	int base_bet;
	Table* table;
	std::list<Bet*>* bets;
	// player owns the bets
	bool log_player;
	int lowest_money, highest_money;

	Player(const std::string&name, int start_money, int base_bet);
	virtual ~Player();

	std::string to_string() const;
	virtual std::string get_player_type() const = 0;
	void set_table(Table* t);
	virtual void make_bets() = 0;
	void track_money();
	void pay_player(int amount);
};

// =================================================================

class PassPlayer : public Player
{
public:
	PassPlayer(const std::string& name, int start_money, int base_bet);
	// virtual ~PassPlayer(); // not needed

	virtual std::string get_player_type() const override;
	void make_bets() override;
};

// =================================================================

class FieldPlayer : public Player
{
public:
FieldPlayer(const std::string& name, int start_money, int base_bet);
	// virtual ~FieldPlayer(); // not needed

	virtual std::string get_player_type() const override;
	void make_bets() override;
};;