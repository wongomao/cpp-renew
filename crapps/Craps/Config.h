#pragma once
#include <string>
#include "json.hpp" // https://github.com/nlohmann/json/blob/develop/README.md#read-json-from-a-file

using json = nlohmann::json;

struct Config
{
	std::string file_path;
	json config_obj;
	//
	Config(std::string file_path);
	//
	std::string get_string(const std::string& key);
	int get_int(const std::string& key);
	bool get_bool(const std::string& key);
};

