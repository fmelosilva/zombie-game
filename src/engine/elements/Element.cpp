#include "Element.hpp"

void Element::setPosition(SDL_Point position)
{
    this->position = position;
}

void Element::setSize(SDL_Point size)
{
    this->size = size;
}

void Element::setRect(SDL_Rect rect)
{
    this->rect = rect;
}

SDL_Point Element::getPosition()
{
    return this->position;
}

SDL_Point Element::getSize()
{
    return this->size;
}

SDL_Rect Element::getRect()
{
    return this->rect;
}

void Element::setAsset(Asset *asset)
{
    this->asset = asset;
}

Asset *Element::getAsset()
{
    return this->asset;
}