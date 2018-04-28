#include "FontAsset.hpp"

AssetType FontAsset::getType()
{
    return AssetType::FONT;
}

void FontAsset::fromFile(std::string path)
{
    this->font = TTF_OpenFont( path.c_str(), 28 );
}

TTF_Font* FontAsset::getFont()
{
    return this->font;
}