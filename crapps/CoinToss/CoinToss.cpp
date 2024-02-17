// CoinToss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <format>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    int iterations = 2000;
	int bet = 5;
	int sum_wins = 0;
	int sum_bets = 0;

	// win = heads, toss = 0
    int toss_count = 0;
	while (toss_count < iterations)
	{
		sum_bets += bet;
		int toss = dis(gen);
		if (toss == 0)
		{
			sum_wins += bet + bet;
		}
		else
		{
			// lost
		}
		toss_count++;
		float win_rate = (float)sum_wins / (float)sum_bets * 100.0f;
		std::string rtpStr = std::format("RTP: {:.1f}", win_rate);
		if (toss_count % (iterations / 20) == 0)
		{
			std::cout << "Toss: " << toss_count << "\tRTP: " << rtpStr << std::endl;
		}
	}
}
/*
this is a simple coin toss game, where the player bets 5 and if the coin lands on heads, the player wins 10, if it lands on tails, the player loses 5
This is a fair game, as the RTP is 100% (50% chance of winning)
There is no house edge with an RTP of 100%.
example output near end:
Toss: 181000    RTP: 100.096
Toss: 182000    RTP: 100.113
Toss: 183000    RTP: 100.144
Toss: 184000    RTP: 100.135
Toss: 185000    RTP: 100.134
Toss: 186000    RTP: 100.128
Toss: 187000    RTP: 100.117
Toss: 188000    RTP: 100.111
Toss: 189000    RTP: 100.109
Toss: 190000    RTP: 100.096
Toss: 191000    RTP: 100.103
Toss: 192000    RTP: 100.062
Toss: 193000    RTP: 100.087
Toss: 194000    RTP: 100.086
Toss: 195000    RTP: 100.076
Toss: 196000    RTP: 100.058
Toss: 197000    RTP: 100.028
Toss: 198000    RTP: 100.029
Toss: 199000    RTP: 100.044
Toss: 200000    RTP: 100.07
*/