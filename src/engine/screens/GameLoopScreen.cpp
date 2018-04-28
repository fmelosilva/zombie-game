#include "GameLoopScreen.hpp"
#include "SDL2/SDL.h"

GameLoopScreen::GameLoopScreen(unsigned int MS_PER_UPDATE)
{
    this->isRunning = true;
    this->MS_PER_UPDATE = MS_PER_UPDATE;
}

void GameLoopScreen::run()
{
    unsigned int previous = SDL_GetTicks();
    unsigned int previous_update = SDL_GetTicks();
    unsigned int lag = 0;

    while (running())
    {
        unsigned int current = SDL_GetTicks();
        unsigned int elapsed = current - previous;
        previous = current;
        lag += elapsed;

        handleEvents();

        while (lag >= this->MS_PER_UPDATE)
        {
            unsigned int current_update = SDL_GetTicks();
            unsigned int elapsed_update = current_update - previous_update;
            previous_update = current_update;

            update(elapsed_update);
            lag -= this->MS_PER_UPDATE;
        }
        render();
    }
    // return next_state(); 
}

bool GameLoopScreen::running()
{
    return this->isRunning;
}