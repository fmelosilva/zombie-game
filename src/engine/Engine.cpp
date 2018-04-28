#include "Engine.hpp"

INITIALIZE_EASYLOGGINGPP

Video *Engine::video = new Video();
std::stack<Screen*> *Engine::screens = new std::stack<Screen*>();

Engine::Engine()
{
}

int Engine::initEngine()
{
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.set(el::Level::Global, el::ConfigurationType::Format, "[%datetime] %level %fbase:%line <<%func>> : %msg");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToFile, "false");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToStandardOutput, "true");
    el::Loggers::reconfigureLogger("default", defaultConf);
}

int Engine::initVideoSystem(Config *config)
{
    video->createWindow(config);
}

void Engine::push_screen(Screen *screen)
{
    screens->push(screen);
}

void Engine::startGame()
{
    Screen *curr_screen = screens->top();
    curr_screen->run();
}