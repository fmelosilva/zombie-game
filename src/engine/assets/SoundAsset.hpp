#ifndef SOUND_ASSET_H_DEFINED
#define SOUND_ASSET_H_DEFINED

#include "Asset.hpp"

class SoundAsset : public Asset
{
  public:
	AssetType getType();
	void fromFile(std::string path);
};

#endif /* SOUND_ASSET_H_DEFINED */
