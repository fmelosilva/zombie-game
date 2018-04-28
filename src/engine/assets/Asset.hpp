#ifndef ASSET_H_DEFINED
#define ASSET_H_DEFINED

#include <map>
#include <string>

enum AssetType
{
	FONT,
	SOUND,
	IMAGE,
	SPRITE
};

const std::map<std::string, AssetType> assetTypeName = {
	{"font", FONT},
	{"sound", SOUND},
	{"image", IMAGE},
	{"sprite", SPRITE}};

class Asset
{
  public:
	virtual AssetType getType() = 0;
	virtual void fromFile(std::string path) = 0;
};

#endif /* ASSET_H_DEFINED */