#ifndef ELEMENT_HPP_DEFINED
#define ELEMENT_HPP_DEFINED

#include "../assets/Asset.hpp"

#include <string>
#include "SDL2/SDL.h"

class Element
{
  public:
    void setPosition(SDL_Point position);
    void setSize(SDL_Point size);
    void setRect(SDL_Rect rect);

    SDL_Point getPosition();
    SDL_Point getSize();
    SDL_Rect getRect();

    void setAsset(Asset *asset);
    Asset *getAsset();

    virtual SDL_Texture *getTexture() = 0;

  private:
    SDL_Point position;
    SDL_Point size;
    SDL_Rect rect;
    Asset *asset;
};

#endif /* ELEMENT_HPP_DEFINED */