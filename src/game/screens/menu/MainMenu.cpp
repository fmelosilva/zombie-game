#include "MainMenu.hpp"

#include "SDL2/SDL.h"
#include "../../../engine/AssetManager.hpp"
#include "../../../engine/assets/FontAsset.hpp"
#include "../../../engine/elements/Text.hpp"
#include "../../../engine/Engine.hpp"

void MainMenu::run()
{
    FontAsset *font = (FontAsset*)AssetManager::getAssetByID("menufont");
    Text *text = new Text("Zombie Game");
    text->setAsset(font);
    SDL_SetRenderDrawColor( Engine::video->getRenderer(), 255, 255, 255, 255 );
    SDL_RenderClear( Engine::video->getRenderer() );
    Engine::video->render(text);
    Engine::video->updateScreen();
    SDL_Delay(5000);
}