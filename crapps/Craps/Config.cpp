#include <fstream>
#include <string>
#include "Config.h"
#include "easylogging++.h"

//#define PATH_TO_CRAPS_CONF "C:\\dv\\cpp\\cpp-renew\\crapps\\Craps\\craps.conf"

Config::Config(std::string file_path): file_path(file_path)
{
	try
	{
		std::ifstream f(file_path);
		config_obj = nlohmann::json::parse(f);
	}
	catch (const std::exception& e)
	{
		LOG(ERROR) << "Error reading configuration file: " << e.what();
	}
}


std::string Config::get_string(const std::string& key)
{
	if (!config_obj[key].is_null() && config_obj[key].is_string())
	{
		return config_obj[key].get<std::string>();
	}
	return "";
}

int Config::get_int(const std::string& key)
{
	if (!config_obj[key].is_null() && config_obj[key].is_number_integer())
	{
		return config_obj[key].get<int>();
	}
	return 0;
}


bool Config::get_bool(const std::string& key)
{
	if (!config_obj[key].is_null() && config_obj[key].is_boolean())
	{
		return config_obj[key].get<bool>();
	}
	return false;
}
