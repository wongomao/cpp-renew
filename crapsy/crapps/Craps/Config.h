#pragma once
#include <map>
#include <string>

struct Config
{
	std::multimap<std::string, std::string> mmap;
	void start_config();
	std::string get_value(const std::string& key);
};

