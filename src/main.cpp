#include "utils/easylogging++.hpp"
#include "Config.hpp"
#include "SDL2/Window.hpp"
#include <SDL2/SDL.h>
#include "Game.hpp"

INITIALIZE_EASYLOGGINGPP

unsigned int MS_PER_UPDATE = 1000/60;
const char *WINDOW_CONFIG_FILE = "./config/window.default.yaml";

void LOGConfig()
{
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.set(el::Level::Global, el::ConfigurationType::Format, "%datetime %level %fbase:%line <%func> : %msg");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToFile, "false");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToStandardOutput, "true");
    el::Loggers::reconfigureLogger("default", defaultConf);
}

bool gameInit(Game *game)
{
    Config *windowConfig = new Config();
    Window *window = new Window();

    LOG(DEBUG) << "Reading window configurations from file";
    if (windowConfig->fromFile(WINDOW_CONFIG_FILE))
        return true;
    if (window->create(windowConfig))
        return true;

    game->setWindow(window);
    return false;
}

void gameLoop(Game *game)
{

    unsigned int previous = SDL_GetTicks();
    unsigned int previous_update = SDL_GetTicks();
    unsigned int lag = 0;

    while (game->running())
    {
        unsigned int current = SDL_GetTicks();
        unsigned int elapsed = current - previous;
        previous = current;
        lag += elapsed;

        game->handleEvents();

        while (lag >= MS_PER_UPDATE)
        {
            unsigned int current_update = SDL_GetTicks();
            unsigned int elapsed_update = current_update - previous_update;
            previous_update = current_update;

            game->update(elapsed_update);
            lag -= MS_PER_UPDATE;
        }
        game->render();
    }
}

int main(int argc, char **argv)
{
    LOGConfig();

    Game *game = new Game();

    if (gameInit(game))
    {
        return -1;
    }

    gameLoop(game);

    return 0;
}