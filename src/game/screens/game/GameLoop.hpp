#include "../../../engine/screens/GameLoopScreen.hpp"

class GameLoop : public GameLoopScreen
{
  public:
    int init();
    void update(unsigned int dt);
    void render();
    void handleEvents();
};