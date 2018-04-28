#ifndef IMAGE_HPP_DEFINED
#define IMAGE_HPP_DEFINED

#include "Element.hpp"
#include "../assets/ImageAsset.hpp"

class Image : public Element
{
  public:
    SDL_Texture *getTexture();

};

#endif /* IMAGE_HPP_DEFINED */