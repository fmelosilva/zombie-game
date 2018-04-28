#ifndef SPRITE_ASSET_H_DEFINED
#define SPRITE_ASSET_H_DEFINED

#include "Asset.hpp"

class SpriteAsset : public Asset
{
  public:
	AssetType getType();
	void fromFile(std::string path);
};

#endif /* SPRITE_ASSET_H_DEFINED */
