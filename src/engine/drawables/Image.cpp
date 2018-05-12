#include "Image.hpp"

SDL_Texture *Image::getTexture()
{
    ImageAsset *imageAsset = (ImageAsset*)getAsset();
    return imageAsset->getTexture();
}