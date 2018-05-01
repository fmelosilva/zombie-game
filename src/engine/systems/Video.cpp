#include "Video.hpp"
#include <stdexcept>
#include <string>

Video::Video(Config config)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error("Unable to initialize video: " + std::string(SDL_GetError()));

    LOG(DEBUG) << "Video system has been initialised";

    this->config = config;

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        LOG(WARNING) << "Linear texture filtering not enabled";

    this->window = SDL_CreateWindow(
        config.get("title").c_str(),
        config.getInt("x"),
        config.getInt("y"),
        config.getInt("width"),
        config.getInt("height"),
        config.getInt("flags"));

    if (!this->window)
        throw std::runtime_error("Window could not be created. SDL_Error: " + std::string(SDL_GetError()));

    LOG(DEBUG) << "A new window was created";

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(this->renderer, config.getInt("width"), config.getInt("height"));

    if (!this->renderer)
        throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
}

SDL_Renderer *Video::getRenderer()
{
    return this->renderer;
}

void Video::render(Element *element)
{
    SDL_Rect Message_rect;
    Message_rect.x = 0;  //controls the rect's x coordinate
    Message_rect.y = 0; // controls the rect's y coordinte
    Message_rect.w = 300; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    SDL_RenderCopy(
        this->renderer,
        element->getTexture(),
        NULL,
        &Message_rect);
}

void Video::updateScreen()
{
    SDL_RenderPresent(this->renderer);
}

Video::~Video()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}
