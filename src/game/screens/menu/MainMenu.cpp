#include "MainMenu.hpp"

#include "SDL2/SDL.h"
#include "../../../engine/AssetManager.hpp"
#include "../../../engine/elements/Image.hpp"
#include "../../../engine/Engine.hpp"

void MainMenu::run()
{
    ImageAsset *imageAsset = (ImageAsset*)AssetManager::getAssetByID("testimage");
    Image *image = new Image();
    image->setAsset(imageAsset);
    Engine::video->render(image);
    Engine::video->updateScreen();
    SDL_Delay(5000);
};