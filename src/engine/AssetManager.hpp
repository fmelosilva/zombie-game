#ifndef ASSET_MANAGER_H_DEFINED
#define ASSET_MANAGER_H_DEFINED

#include <string>
#include "assets/Asset.hpp"
#include "utils/easylogging++.hpp"
#include "yaml-cpp/yaml.h"

class AssetManager
{
public:
    static void fromFile(std::string path);
    static Asset *getAssetByID(std::string id);

private:
    static std::map<std::string, Asset *> asset_map;
    static Asset *createAssetFromEnum(AssetType asset_type);
    static Asset *createAssetFromString(std::string asset_type);
};

#endif /* ASSET_MANAGER_H_DEFINED */
