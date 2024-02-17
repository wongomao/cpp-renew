#pragma once
#include <string>
#include <format>
#include <list>

class Table;
class Bet;

class Player
{
private:
	int money; // current holdings
	bool first_time_below_zero;
public:
	std::string name;
	int start_money;
	int base_bet;
	int sum_bets;
	int sum_wins;
	Table* table;
	std::list<Bet*>* bets;
	// player owns the bets
	int lowest_money, highest_money;

	Player(const std::string&name, int start_money, int base_bet);
	virtual ~Player();

	std::string to_string() const;
	void log_player();
	virtual std::string get_player_type() const = 0;
	void set_table(Table* t);
	virtual void make_bets() = 0;
	void subtract_bet_amount(int bet_amount);
	void track_money(int roll_iteration);
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