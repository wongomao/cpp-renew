#include <fstream>
#include <map>
#include <string>
#include <regex>
#include "Config.h"
#include "easylogging++.h"

#define PATH_TO_CRAPS_CONF "C:\\dv\\cpp\\cpp-renew\\crapps\\Craps\\craps.conf"

void Config::start_config()
{
	mmap = std::multimap<std::string, std::string>();
	// map["test"] = "test value";
	std::ifstream config_file(PATH_TO_CRAPS_CONF);
	if (!config_file.is_open())
	{
		LOG(ERROR) << "Unable to open config file " << PATH_TO_CRAPS_CONF;
		return;
	}
	// comments in the conf file begin with a hash
	std::string line;
	std::regex re("([a-zA-Z_]+)\\s*=\\s*([a-zA-Z0-9_\\(\\)\\,]+)");
	while (std::getline(config_file, line))
	{
		// skip comments
		if (line[0] == '#')
		{
			continue;
		}
		std::smatch match;
		if (std::regex_search(line, match, re))
		{
			mmap.insert(std::make_pair(match[1].str(), match[2].str()));
		}
	}
	config_file.close();
	if (get_value("ECHO_ALL_CONFIGURATIONS") == "true")
	{
		LOG(INFO) << "Configuration values (" << PATH_TO_CRAPS_CONF << "):";
		for (auto it = mmap.begin(); it != mmap.end(); ++it)
		{
			LOG(INFO) << it->first << " => " << it->second;
		}
	}
}

std::string Config::get_value(const std::string& key)
{
	auto search = mmap.find(key);
	if (search != mmap.end())
	{
		return search->second;
	}
	return "";
}