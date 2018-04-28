#include <exception>
#include "Config.hpp"
#include "../utils/easylogging++.hpp"

void Config::fromFile(std::string path)
{

	LOG(DEBUG) << "Loading configuration from " << path << ".";
	YAML::Node config = YAML::LoadFile(path);
	LOG(INFO) << path << '\n' << config;
	this->config = config;
}

bool Config::has(std::string key)
{
	return this->config[key].as<std::string>() != "";
}

std::string Config::get(std::string key)
{
	return this->config[key].as<std::string>();
}

bool Config::getBool(std::string key)
{
	return this->config[key].as<bool>();
}

int Config::getInt(std::string key)
{
	return this->config[key].as<int>();
}