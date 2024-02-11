#include <string>
#include "Table.h"
#include "Player.h"
#include "Bet.h"
#include "easylogging++.h"
#include "Config.h"

// ====================================================================================================================================================================
Table::Table(Config config) : config(config),
	bank(1000000), gen(rd()), dis(1, 6), die1(0), die2(0), point(0)
{
	players = new std::list<Player*>();
	bets = new std::list<Bet*>();
	log_rolls = config.map["LOG_ROLLS"] == "true";
	using_preroll = false;
	preroll = { {1, 1}, {3, 4}, {6, 6} };
	preroll_id = 0;
	roll_bucket = std::vector<int>(13, 0); // extra element at indexes 0,1
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

void Table::play()
{
	int roll_count = 0;
	int minimum_iterations = std::stoi(config.map["ITERATIONS_MIN"]);
	bool keep_playing = true;
	LOG(INFO) << "------ game end -----";
	while (keep_playing)
	{
		accept_bets();
		roll();
		adjudicate_bets();
		calculate_new_point();
		if (log_rolls)
		{
			LOG(INFO) << "roll: " << die1 << "," << die2 << "; point = " << point;
		}

		roll_count++;
		if (roll_count >= minimum_iterations)
		{
			keep_playing = point != 0;
		}
	}
	LOG(INFO) << "------ game end -----";
}

void Table::log_players()
{
	LOG(INFO) << "Players: ";
	for (auto p : *players)
	{
		LOG(INFO) << "\t" << p->to_string();
	}
}

void Table::log_bets()
{
	std::string no_bets = bets->empty() ? "none" : "";
	LOG(INFO) << "All Table Bets: " << no_bets;
	for (auto b : *bets)
	{
		LOG(INFO) << "\t" << b->to_string();
	}
}

void Table::log_bank()
{
	std::string logMsg = "Bank: $" + std::to_string(bank);
	int roll_count = 0;
	for (int i = 2; i < roll_bucket.size(); i++)
	{
		roll_count += roll_bucket[i];
	}
	logMsg += "\n" + std::to_string(roll_count) + " Rolls; Distribution:";
	for (int i = 2; i < roll_bucket.size(); i++)
	{
		float percent = (float)roll_bucket[i] / roll_count * 100;
		int percent_int = (int)percent;
		std::string asterisks = "";
		for (int j = 0; j < percent_int; j++)
		{
			asterisks += "*";
		}
		if (i < 10)
			logMsg += "\n " + std::to_string(i) + ": " + asterisks;
		else
			logMsg += "\n" + std::to_string(i) + ": " + asterisks;
	}
	LOG(INFO) << logMsg;
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
		LOG(ERROR) << "Table::accept_bet() received a null bet";
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
	roll_bucket[die1 + die2]++;
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
}

int Table::get_point()
{
	return point;
}

void Table::pay_table(int amount)
{

	bank += amount;
}
