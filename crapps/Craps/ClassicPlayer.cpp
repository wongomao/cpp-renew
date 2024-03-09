#include "ClassicPlayer.h"
#include "Table.h"

ClassicPlayer::ClassicPlayer(const std::string& name, int start_money)
	: Player(name, start_money, 0),
	place_numbers(new std::list<std::pair<int, int>>()),
	hardway_numbers(new std::list<std::pair<int, int>>()),
	pass_bet_amount(0),
	odds_bet_multiplier(0)
	{}

ClassicPlayer::~ClassicPlayer()
{
	delete place_numbers;
	place_numbers = nullptr;
	delete hardway_numbers;
	hardway_numbers = nullptr;
}

std::string ClassicPlayer::get_player_type() const
{
	return "Classic";
}

void ClassicPlayer::add_place_number(int place_number, int bet_amount)
{
	std::pair<int, int> p = std::make_pair(place_number, bet_amount);
	place_numbers->push_back(p);
}

void ClassicPlayer::add_hardway_number(int hardway_number, int bet_amount)
{
	std::pair<int, int> p = std::make_pair(hardway_number, bet_amount);
	hardway_numbers->push_back(p);
}

void ClassicPlayer::make_bets()
{
	if (bets->size() > 0)
	{
		for (auto b : *bets)
		{
			if (!b->get_active())
			{
				subtract_bet_amount(b->amount);
				b->set_active(true);
				table->accept_bet(b);
			}
		}
	}
	else
	{
		// bet pass line
		subtract_bet_amount(pass_bet_amount); // this is actual
		int odds_bet_amount = pass_bet_amount * odds_bet_multiplier;
		auto odds_bet = new PassOddsBet(this, pass_bet_amount, odds_bet_amount);
		// odds bet is not yet active, amount subtracted only when point is established
		table->accept_bet(odds_bet); // add to table's list of bets
		bets->push_back(odds_bet); // add to player's list of bets

		// bet all place numbers
		for (auto place_number_pair : *place_numbers)
		{
			int place_number = place_number_pair.first;
			int bet_amount = place_number_pair.second;
			subtract_bet_amount(bet_amount);

			auto bet = new PlaceBet(this, bet_amount, place_number);
			bet->off_on_come_out = true;
			bets->push_back(bet);
			table->accept_bet(bet);
		}

		// bet all hardways
		for (auto hardway_number_pair : *hardway_numbers)
		{
			int hardway_number = hardway_number_pair.first;
			int bet_amount = hardway_number_pair.second;
			subtract_bet_amount(bet_amount);

			auto bet = new HardwaysBet(this, bet_amount, hardway_number);
			bet->off_on_come_out = true;
			bets->push_back(bet);
			table->accept_bet(bet);
		}
	}
}