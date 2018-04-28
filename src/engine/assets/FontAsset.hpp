#ifndef FONT_ASSET_H_DEFINED
#define FONT_ASSET_H_DEFINED

#include "Asset.hpp"

#include "SDL2/SDL_ttf.h"

class FontAsset : public Asset
{
  public:
  	AssetType getType();
		void fromFile(std::string path);

	TTF_Font *getFont();

  private:
	TTF_Font *font;
};

#endif /* FONT_ASSET_H_DEFINED */