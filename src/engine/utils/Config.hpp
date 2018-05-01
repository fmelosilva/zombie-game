#ifndef CONFIG_H_DEFINED
#define CONFIG_H_DEFINED

#include <string>
#include "yaml-cpp/yaml.h"

class Config
{
  public:
		static std::map<std::string, Config> createConfigMapFromFile(std::string path);

		Config();
		Config(YAML::Node config); 

		bool has(std::string key);

		std::string get(std::string key);
		bool getBool(std::string key);
		int getInt(std::string key);

		void set(std::string key, std::string value);
		void set(std::string key, bool value);
		void set(std::string key, int value);

  private:
		std::string path;
		YAML::Node config;

};

#endif /* CONFIG_H_DEFINED */