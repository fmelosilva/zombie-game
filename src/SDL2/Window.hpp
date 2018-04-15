#ifndef WINDOW_H_DEFINED
#define WINDOW_H_DEFINED

#include <SDL2/SDL.h>
#include "../utils/easylogging++.hpp"
#include "../Config.hpp"

class Window
{
  public:
    ~Window();
    bool create(Config *config);
    void render();

  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Config *window_settings;
};

#endif /* WINDOW_H_DEFINED */