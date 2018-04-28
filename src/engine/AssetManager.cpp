#include "AssetManager.hpp"

#include "assets/FontAsset.hpp"
#include "assets/SoundAsset.hpp"
#include "assets/SpriteAsset.hpp"
#include "assets/ImageAsset.hpp"


std::map<std::string, Asset *> AssetManager::asset_map;

void AssetManager::fromFile(std::string path)
{
    YAML::Node elem = YAML::LoadFile(path);
    YAML::Node file_assets = elem["assets"];

    LOG(DEBUG) << "Initializing Asset Manager from " << path << ".";
    for (YAML::const_iterator it = file_assets.begin(); it != file_assets.end(); ++it)
    {
        const YAML::Node asset = it->as<YAML::Node>();
        const std::string id = asset["id"].as<std::string>();
        const std::string path = asset["path"].as<std::string>();
        const std::string type = asset["type"].as<std::string>();

        LOG(INFO) << '\n' << asset;

        Asset *new_asset = AssetManager::createAssetFromString(type);
        new_asset->fromFile(path);
        asset_map.insert({id, new_asset});
    }
}

Asset *AssetManager::createAssetFromEnum(AssetType asset_type)
{
    switch (asset_type)
    {
    case FONT:
        return new FontAsset();
    case IMAGE:
        return new ImageAsset();
    case SPRITE:
        return new SpriteAsset();
    case SOUND:
        return new SoundAsset();
    default:
        return nullptr;
    }
}

Asset *AssetManager::createAssetFromString(std::string asset_type)
{
    Asset *asset = nullptr;
    try
    {
        AssetType assetType = assetTypeName.at(asset_type);
        asset = AssetManager::createAssetFromEnum(assetType);
    }
    catch (std::out_of_range const &exc)
    {
        LOG(ERROR) << asset_type << " does not match with any asset type.";
    }
    return asset;
}

Asset *AssetManager::getAssetByID(std::string id)
{
    return asset_map[id];
}