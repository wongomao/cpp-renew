#pragma once
#include <map>
#include <string>

struct Config
{
	std::map<std::string, std::string> map;
	void start_config();
};

