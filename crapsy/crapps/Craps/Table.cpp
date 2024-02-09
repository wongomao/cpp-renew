#include <string>
#include "Table.h"
#include "Player.h"
#include "Bet.h"
#include "Logger.h"

// ====================================================================================================================================================================
Table::Table() : bank(1000000), gen(rd()), dis(1, 6), die1(0), die2(0), point(0)
{
	players = new std::list<Player*>();
	bets = new std::list<Bet*>();
	using_preroll = false;
	preroll = { {1, 1}, {3, 4}, {6, 6} };
	preroll_id = 0;
}

Table::~Table()
{
	delete players;
	players = nullptr;
	delete bets;
	bets = nullptr;
}
// ====================================================================================================================================================================

void Table::set_using_preroll(bool b)
{
	using_preroll = b;
}

void Table::add_player(Player* p)
{
	players->push_back(p);
	p->set_table(this);
}

void Table::log_players()
{
	std::string logMsg = "Players: ";
	for (auto p : *players)
	{
		logMsg += "\n\t" + p->to_string();
	}
	Logger::log(Level::INFO, logMsg.c_str());
}

void Table::log_bets()
{
	std::string logMsg = "All Table Bets: ";
	for (auto b : *bets)
	{
		logMsg += "\n\t" + b->to_string();
	}
	Logger::log(Level::INFO, logMsg.c_str());
}

void Table::accept_bets()
{
	for (auto p : *players)
	{
		p->make_bets();
	}
}

void Table::accept_bet(Bet* b)
{
	if (b != nullptr)
	{
		b->set_table(this);
		bets->push_back(b);
	}
	else
	{
		std::string logMsg = "Table::accept_bet() received a null bet";
		Logger::log(Level::ERROR, logMsg.c_str());
	}
}

void Table::roll()
{
	if (using_preroll)
	{
		die1 = preroll[preroll_id].first;
		die2 = preroll[preroll_id].second;
		preroll_id = (preroll_id + 1) % preroll.size();
	}
	else
	{
		die1 = dis(gen);
		die2 = dis(gen);
	}
	std::string logMsg = "roll: " + std::to_string(die1) + ", " + std::to_string(die2);
	Logger::log(Level::INFO, logMsg.c_str());

	adjudicate_bets();
	calculate_new_point();
}

void Table::adjudicate_bets()
{
	// loop through bets and adjudicate each one
	for (std::list<Bet*>::iterator it = bets->begin(); it != bets->end();)
	{
		Bet *b = *it; // dereference the iterator to get the pointer to the bet object
		// adjudicate the bet, pay player or table as needed
		bool leave_on_table = b->adjudicate(die1, die2, point);
		if (!leave_on_table)
		{
			b->set_active(false); // set the bet to inactive / taken off table
			it = bets->erase(it); // remove the bet from the list
			// assuming erase() returns the next iterator, so no need to increment it
		}
		else
		{
			++it; // move to the next bet
		}
	}
}

// this function is called after the dice are rolled
// to calculate the point for the next roll
void Table::calculate_new_point()
{
	if (point == 0)
	{
		if (die1 + die2 == 7 || die1 + die2 == 11)
		{
			point = 0;
		}
		else if (die1 + die2 == 2 || die1 + die2 == 3 || die1 + die2 == 12)
		{
			point = 0;
		}
		else
		{
			point = die1 + die2;
		}
	}
	else
	{
		if (die1 + die2 == 7)
		{
			point = 0;
		}
		else if (die1 + die2 == point)
		{
			point = 0;
		}
	}
	std::string logMsg = "point is now " + std::to_string(point);
	Logger::log(Level::INFO, logMsg.c_str());
}

void Table::pay_table(int amount)
{

	bank += amount;
}
