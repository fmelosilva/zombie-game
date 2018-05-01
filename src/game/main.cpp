#include "../engine/Engine.hpp"
#include "../engine/AssetManager.hpp"
#include "screens/menu/MainMenu.hpp"

const char *WINDOW_CONFIG_FILE = "./config/systems.default.yaml";
const char *ASSET_LIST_FILE = "./config/assets.yaml";


int main(int argc, char **argv)
{
    Engine::initEngine();

    Engine::initSystems(
        Config::createConfigMapFromFile(WINDOW_CONFIG_FILE)
    );
    AssetManager::fromFile(ASSET_LIST_FILE);

    MainMenu *menu = new MainMenu();
    Engine::push_screen(menu);
    Engine::startGame();

    return 0;
}