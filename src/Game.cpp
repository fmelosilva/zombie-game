#include "Game.hpp"

Game::Game()
{
    LOG(INFO) << "--> Starting Zombie Game <--";

}

bool Game::setWindow(Window *window)
{
    this->window = window;
}

bool Game::running()
{
    return isRunning;
}

void Game::handleEvents()
{
    SDL_Event event;
    /*
        TODO: 
        Control::createEvent([w,a,s,d,shift],&movimentListener);
        Control::createEvent([mouseDown],&fireListener);
        Control::createEvent([r],&reloadListener);
    */
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
        }
    }
}

void Game::update(float dt)
{
}

void Game::render()
{
}