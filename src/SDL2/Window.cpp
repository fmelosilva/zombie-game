#include "Window.hpp"

bool Window::create(Config *config)
{
    SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        LOG(ERROR) << "Unable to initialize SDL: " + std::string(SDL_GetError());
        return true;
    }
    LOG(DEBUG) << "SDL Video initialised.";

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        LOG(WARNING) << "Linear texture filtering not enabled.";

    window = SDL_CreateWindow(
        config->get("window_title").c_str(),
        config->getInt("x_position"),
        config->getInt("y_position"),
        config->getInt("width"),
        config->getInt("height"),
        config->getInt("flags"));

    if (!window)
    {
        LOG(ERROR)  << "Window could not be created. SDL_Error: " + std::string(SDL_GetError());
        return true;
    }

    LOG(DEBUG) << "Window created.";


    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        LOG(ERROR) << "Renderer could not be created! SDL_Error: " << std::string(SDL_GetError());
        return true;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    this->window = window;
    this->renderer = renderer;
    return false;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
