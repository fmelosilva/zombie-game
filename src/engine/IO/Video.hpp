#ifndef VIDEO_H_DEFINED
#define VIDEO_H_DEFINED

#include <SDL2/SDL.h>
#include "../utils/Config.hpp"
#include "../utils/easylogging++.hpp"
#include "../drawables/Drawable.hpp"


class Video
{
  public:
    Video(Config config);
    ~Video();
    SDL_Renderer *getRenderer();
    void render(Drawable *drawable);
    void updateScreen();

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Config config;
};

#endif /* VIDEO_H_DEFINED */