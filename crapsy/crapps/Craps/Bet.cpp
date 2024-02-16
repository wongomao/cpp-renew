#include "Bet.h"
#include "Player.h"
#include "Table.h"

Bet::Bet(Player* p, int amt)
	: table(nullptr), player(p), amount(amt), active(true)
{
}

Bet::~Bet()
{
}

std::string Bet::to_string() const
{
	return player->to_string() + " bets $" + std::to_string(amount) + " on UNKNOWN";
}

void Bet::set_table(Table* t)
{
	table = t;
}

void Bet::set_active(bool a)
{
	active = a;
}

bool Bet::get_active() const
{
	return active;
}

void Bet::pay_table(int amount)
{
	if (table != nullptr)
	{
		table->pay_table(amount);
	}
}

void Bet::pay_player(int amount)
{
	if (player != nullptr)
	{
		player->pay_player(amount);
	}
}

// =================================================================

PassBet::PassBet(Player* p, int amt)
	: Bet(p, amt) {}

std::string PassBet::to_string() const
{
	return "$" + std::to_string(amount) + " on Pass";
}

bool PassBet::adjudicate(int die1, int die2, int point)
{
    bool leaveOnTable = true;
    // point is 0 if it is the come-out roll
    if (point == 0)
    {
        if (die1 + die2 == 7 || die1 + die2 == 11)
        {
            pay_table(-amount); // subtract amount from table
            pay_player(amount);
        }
        else if (die1 + die2 == 2 || die1 + die2 == 3 || die1 + die2 == 12)
        {
            pay_table(amount);
            leaveOnTable = false; // mark the bet to be removed from the table
        }
    }
    else
    {
        if (die1 + die2 == point)
        {
            pay_table(-amount); // subtract amount from table
            pay_player(amount);
        }
        else if (die1 + die2 == 7)
        {
            pay_table(amount);
            leaveOnTable = false; // mark the bet to be removed from the table
        }
    }
    return leaveOnTable;
}

// =================================================================

FieldBet::FieldBet(Player* p, int amt)
	: Bet(p, amt) {}

std::string FieldBet::to_string() const
{
	return "$" + std::to_string(amount) + " on Field";
}

bool FieldBet::adjudicate(int die1, int die2, int point)
{
    // field bet is a one-roll bet : it is always removed from the table
    bool leaveOnTable = false;
    int rollValue = die1 + die2;
    if (rollValue == 2)
    {
        pay_table(-amount * 2); // subtract amount from table
        pay_player(amount * 2 + amount); // hand back original + 2x
    }
    else if (rollValue == 12)
    {
		pay_table(-amount * 3); // subtract amount from table
		pay_player(amount * 3 + amount); // hand back original + 3x
	}
    else if (rollValue == 3 || rollValue == 4 || rollValue == 9 || rollValue == 10 || rollValue == 11)
    {
        pay_table(-amount); // subtract amount from table
        pay_player(amount + amount); // hand back original + 1x
    }
    else
    {
        pay_table(amount); // table wins
    }
    return leaveOnTable;
}

// =================================================================
