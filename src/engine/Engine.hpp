#include <stack>
#include "systems/Video.hpp"
#include "systems/Config.hpp"
#include "screens/Screen.hpp"

class Engine
{
  public:
    Engine();
    ~Engine();
    static int initEngine();
    static int initVideoSystem(Config *config);
    static void startGame();
    static void push_screen(Screen *screen);

    static Video *video;

  private:
    
    static std::stack<Screen*> *screens;
};
