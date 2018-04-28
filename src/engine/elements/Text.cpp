#include "Text.hpp"
#include "../Engine.hpp"
#include "SDL2/SDL_image.h"

Text::Text(std::string text)
{
    this->text = text;
}

void Text::setColor(SDL_Color color)
{
    this->color = color;
}

SDL_Texture *Text::getTexture()
{
    return nullptr;
}
