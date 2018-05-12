#include <stack>
#include "IO/Video.hpp"
#include "utils/Config.hpp"
#include "screens/Screen.hpp"
#include "SDL2/SDL_ttf.h"

class Engine
{
  public:
    Engine();
    ~Engine();
    static int initEngine();
    static int initVideoSystem(Config *config);
    static void initSystems(std::map<std::string, Config> config_map);
    static void startGame();
    static void push_screen(Screen *screen);

    static Video *video;

  private:
    static std::stack<Screen*> *screens;
    
};
