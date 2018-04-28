#include "../engine/systems/Config.hpp"
#include "../engine/systems/Video.hpp"
#include "../engine/Engine.hpp"
#include "../engine/AssetManager.hpp"
#include "screens/menu/MainMenu.hpp"

const char *WINDOW_CONFIG_FILE = "./config/window.default.yaml";
const char *ASSET_LIST_FILE = "./config/assets.yaml";


int main(int argc, char **argv)
{
    Engine::initEngine();

    Config *windowConfig = new Config();
    windowConfig->fromFile(WINDOW_CONFIG_FILE);
    Engine::initVideoSystem(windowConfig);
    AssetManager::fromFile(ASSET_LIST_FILE);
    MainMenu *menu = new MainMenu();
    Engine::push_screen(menu);
    Engine::startGame();


    return 0;
}