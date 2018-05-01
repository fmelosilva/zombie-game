#ifndef VIDEO_H_DEFINED
#define VIDEO_H_DEFINED

#include <SDL2/SDL.h>
#include "../utils/Config.hpp"
#include "../utils/easylogging++.hpp"
#include "../elements/Element.hpp"


class Video
{
  public:
    Video(Config config);
    ~Video();
    SDL_Renderer *getRenderer();
    void render(Element *element);
    void updateScreen();

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Config config;
};

#endif /* VIDEO_H_DEFINED */