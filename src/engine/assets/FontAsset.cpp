#include "FontAsset.hpp"

AssetType FontAsset::getType()
{
    return AssetType::FONT;
}

void FontAsset::fromFile(std::string path)
{
    this->font = TTF_OpenFont(path.c_str(), 24);
    if ( this->font == nullptr )
    {
    	throw std::runtime_error(" Failed to load font : " + std::string(SDL_GetError()));
    }
}

TTF_Font* FontAsset::getFont()
{
    return this->font;
}