#include "Drawable.hpp"

void Drawable::setPosition(SDL_Point position)
{
    this->position = position;
}

void Drawable::setSize(SDL_Point size)
{
    this->size = size;
}

void Drawable::setRect(SDL_Rect rect)
{
    this->rect = rect;
}

SDL_Point Drawable::getPosition()
{
    return this->position;
}

SDL_Point Drawable::getSize()
{
    return this->size;
}

SDL_Rect Drawable::getRect()
{
    return this->rect;
}

void Drawable::setAsset(Asset *asset)
{
    this->asset = asset;
}

Asset *Drawable::getAsset()
{
    return this->asset;
}