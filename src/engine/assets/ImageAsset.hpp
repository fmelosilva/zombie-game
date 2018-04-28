#ifndef IMAGE_ASSET_H_DEFINED
#define IMAGE_ASSET_H_DEFINED

#include "Asset.hpp"

#include "SDL2/SDL.h"

class ImageAsset : public Asset
{
  public:
    AssetType getType();
    void fromFile(std::string path);

    SDL_Texture *getTexture();

  private:
    SDL_Texture *texture;
};

#endif /* IMAGE_ASSET_H_DEFINED */
