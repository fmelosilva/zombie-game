#ifndef TEXT_HPP_DEFINED
#define TEXT_HPP_DEFINED

#include "Element.hpp"
#include "../assets/FontAsset.hpp"

#include <string>
#include "SDL2/SDL_ttf.h"

class Text : public Element
{
  public:
    Text(std::string text);
    ~Text();
    
    void setColor(SDL_Color color);
    SDL_Color getColor();

    SDL_Texture *getTexture();


  private:

    std::string text;
    SDL_Color color;
    SDL_Texture *texture; 

};

#endif /* TEXT_HPP_DEFINED */