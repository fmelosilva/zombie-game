#ifndef IMAGE_HPP_DEFINED
#define IMAGE_HPP_DEFINED

#include "Drawable.hpp"
#include "../assets/ImageAsset.hpp"

class Image : public Drawable
{
  public:
    SDL_Texture *getTexture();

};

#endif /* IMAGE_HPP_DEFINED */