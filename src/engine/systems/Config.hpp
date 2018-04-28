#ifndef CONFIG_H_DEFINED
#define CONFIG_H_DEFINED

#include <string>
#include "yaml-cpp/yaml.h"

class Config
{
  public:
	void fromFile(std::string path);

	bool has(std::string key);

	std::string get(std::string key);

	bool getBool(std::string key);

	int getInt(std::string key);

  private:
	std::string path;
	YAML::Node config;
};

#endif /* CONFIG_H_DEFINED */