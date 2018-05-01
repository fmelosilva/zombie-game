#include "Config.hpp"
#include "easylogging++.hpp"
#include <map>

std::map<std::string, Config> Config::createConfigMapFromFile(std::string path)
{
	LOG(DEBUG) << "Loading " << path << " file.";
	std::map<std::string, Config> map;
	YAML::Node config_array = YAML::LoadFile(path);

	for (YAML::const_iterator it = config_array.begin(); it != config_array.end(); ++it)
	{
		const std::string key = it->first.as<std::string>();
		YAML::Node node = it->second.as<YAML::Node>();
		LOG(DEBUG) << "Reading attributes from > " << key << " <";
		LOG(INFO) << "\n" << node;
		map.insert(std::make_pair(key, Config(node)));
	}

	return map;
}

Config::Config()
{
}

Config::Config(YAML::Node config)
{
	this->config = config;
}

bool Config::has(std::string key)
{
	return this->config[key];
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

void Config::set(std::string key, std::string value)
{
	this->config[key] = value;
}

void Config::set(std::string key, bool value)
{
	this->config[key] = value;
}

void Config::set(std::string key, int value)
{
	this->config[key] = value;
}