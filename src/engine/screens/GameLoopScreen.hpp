#ifndef GAME_LOOP_SCREEN_H_DEFINED
#define GAME_LOOP_SCREEN_H_DEFINED

#include "Screen.hpp"

class GameLoopScreen : public Screen
{
    public:
        GameLoopScreen(unsigned int MS_PER_UPDATE);
        void run();
        virtual int init() = 0;
        bool running();
        virtual void update(unsigned int dt) = 0;
        virtual void render() = 0;
        virtual void handleEvents() = 0;

    private:
        unsigned int MS_PER_UPDATE;
        bool isRunning;
};

#endif /* GAME_LOOP_SCREEN_H_DEFINED */