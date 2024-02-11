#include <fstream>
#include <map>
#include <string>
#include <regex>
#include "Config.h"
#include "easylogging++.h"

#define PATH_TO_CRAPS_CONF "C:\\dv\\cpp\\cpp-renew\\crapsy\\crapps\\Craps\\craps.conf"

void Config::start_config()
{
	map = std::map<std::string, std::string>();
	// map["test"] = "test value";
	std::ifstream config_file(PATH_TO_CRAPS_CONF);
	if (!config_file.is_open())
	{
		LOG(ERROR) << "Unable to open config file " << PATH_TO_CRAPS_CONF;
		return;
	}
	std::string line;
	std::regex re("([a-zA-Z_]+)\\s*=\\s*([a-zA-Z0-9_]+)");
	while (std::getline(config_file, line))
	{
		std::smatch match;
		if (std::regex_search(line, match, re))
		{
			map[match[1].str()] = match[2].str();
		}
	}
	config_file.close();
}