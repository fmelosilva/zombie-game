#include "ImageAsset.hpp"

#include "../Engine.hpp"
#include "SDL2/SDL_image.h"

AssetType ImageAsset::getType()
{
    return IMAGE;
}

void ImageAsset::fromFile(std::string path)
{
    SDL_Surface *tempSurface = IMG_Load(path.c_str());
    this->texture = SDL_CreateTextureFromSurface(Engine::video->getRenderer(), tempSurface);
    SDL_FreeSurface(tempSurface);
}

SDL_Texture *ImageAsset::getTexture()
{
    return this->texture;
}