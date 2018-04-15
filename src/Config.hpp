#ifndef CONFIG_H_DEFINED
#define CONFIG_H_DEFINED

#include <yaml-cpp/yaml.h>
#include <string>

class Config
{
public:
	bool fromFile(std::string filename);

	bool has(std::string key);

	std::string get(std::string key);

	bool getBool(std::string key);

	int getInt(std::string key);


private:
	std::string filename;
	YAML::Node config;
};

#endif /* CONFIG_H_DEFINED */