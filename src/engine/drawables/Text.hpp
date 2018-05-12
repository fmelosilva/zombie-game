#ifndef TEXT_HPP_DEFINED
#define TEXT_HPP_DEFINED

#include "Drawable.hpp"
#include "../assets/FontAsset.hpp"

#include <string>

class Text : public Drawable
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