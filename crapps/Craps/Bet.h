#pragma once
#include <string>

class Table;
class Player;


class Bet
{
public:
	Table* table;
	Player* player;
	int amount;
	bool active;
	bool off_on_come_out; // most bets are not off on come out

	Bet(Player* p, int amt);
	virtual ~Bet();
	virtual std::string to_string() const;
	void set_table(Table* t);
	void set_active(bool a);
	bool get_active() const;
	// adjudicate returns true if the bet is to stay on the table
	virtual bool adjudicate(int die1, int die2, int point) = 0;
	void pay_table(int amount);
	void pay_player(int amount);
};

// =================================================================

class PassBet : virtual public Bet
{
public:
	PassBet(Player* p, int amt);
	std::string to_string() const override;
	bool adjudicate(int die1, int die2, int point) override;
};

// =================================================================

class FieldBet : virtual public Bet
{
public:
	FieldBet(Player* p, int amt);
	std::string to_string() const override;
	bool adjudicate(int die1, int die2, int point) override;
};