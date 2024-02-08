// CrapsLib.cpp : Defines the functions for the static library.
//

#include <iostream>
#include <random>
#include <tuple>

#include "pch.h"
#include "framework.h"

void fnCrapsLib()
{
	std::cout << "Hello from CrapsLib!" << std::endl;
}

std::tuple<int, int> rollDice()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	return { dis(gen), dis(gen) }; // dis(gen) + dis(gen);
}