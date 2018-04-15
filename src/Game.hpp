#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED

#include "Config.hpp"
#include "SDL2/Window.hpp"

class Game
{
public:
	Game();
	~Game();

	bool setWindow(Window *window);

	bool running();
	void update(float dt);
	void render();
	void handleEvents();

private:
	bool isRunning;
	Window *window;

};

#endif /* GAME_H_DEFINED */