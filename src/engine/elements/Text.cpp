#include "Text.hpp"
#include "../Engine.hpp"
#include "SDL2/SDL_image.h"

Text::Text(std::string text)
{
    this->text = text;
    this->color = {255, 255, 255};
}

void Text::setColor(SDL_Color color)
{
    this->color = color;
}

SDL_Texture *Text::getTexture()
{
    FontAsset *fontAsset = (FontAsset*)getAsset();
    SDL_Surface* textSurface = TTF_RenderText_Solid(
        fontAsset->getFont(), 
        this->text.c_str(), 
        this->color );
    this->texture = SDL_CreateTextureFromSurface( Engine::video->getRenderer(), textSurface );
    return this->texture;
}
