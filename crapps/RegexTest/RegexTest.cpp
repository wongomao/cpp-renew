// RegexTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>

int main()
{
    std::string preroll_str = "(1,1),(3,4),(6,6),(5,5)";
    std::regex digit_pair_re("(\\(\\d\\,\\d\\))");
	std::regex digit_re("\\d");
    std::smatch pair_match;
	std::vector<std::pair<int, int>> preroll;

	while (std::regex_search(preroll_str, pair_match, digit_pair_re))
	{
		//std::cout << pair_match[0].str() << std::endl;
		std::string pair_str = pair_match[0].str();

		std::smatch digit_match;
		if (std::regex_search(pair_str, digit_match, digit_re))
		{
			int die1 = std::stoi(digit_match[0].str());
			pair_str = digit_match.suffix().str();
			if (std::regex_search(pair_str, digit_match, digit_re))
			{
				int die2 = std::stoi(digit_match[0].str());
				//std::cout << "die1: " << die1 << " die2: " << die2 << std::endl;
				preroll.push_back(std::make_pair(die1, die2));
			}
		}

		preroll_str = pair_match.suffix().str();
	}

	for (auto p : preroll)
	{
		std::cout << "roll: " << p.first << "," << p.second << std::endl;
	}
}
