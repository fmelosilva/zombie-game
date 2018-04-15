#include <exception>
#include "Config.hpp"
#include "utils/easylogging++.hpp"

bool Config::fromFile(std::string filename)
{
	bool error = true;
	try
	{
		LOG(DEBUG) << "Loading " << filename << " configuration file.";
		this->config = YAML::LoadFile(filename);
		LOG(INFO) << "-- File Content --";
		for (YAML::const_iterator it = this->config.begin(); it != config.end(); ++it)
		{
			LOG(INFO) << it->first.as<std::string>() << ": " << it->second.as<std::string>();
		}
		error = false;
	}
	catch (YAML::BadFile const &exc)
	{
		LOG(ERROR) << "Could not load " << filename << ". File does not exist.";
	}
	catch (YAML::BadConversion const &exc)
	{
		LOG(ERROR) << "Could not load " << filename << ". Text is poorly formed.";
	}
	return error;
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