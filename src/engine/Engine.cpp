#include "Engine.hpp"

INITIALIZE_EASYLOGGINGPP

Video *Engine::video = nullptr;
std::stack<Screen*> *Engine::screens = new std::stack<Screen*>();

Engine::Engine()
{
}

void LOG_Init()
{
    el::Loggers::addFlag(el::LoggingFlag::ColoredTerminalOutput);
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.set(el::Level::Global, el::ConfigurationType::Format, "[%datetime] %level %fbase:%line : %msg");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToFile, "false");
    defaultConf.set(el::Level::Global, el::ConfigurationType::ToStandardOutput, "true");
    el::Loggers::reconfigureLogger("default", defaultConf);
}

int Engine::initEngine()
{
    LOG_Init();
    TTF_Init();
}

void Engine::initSystems(std::map<std::string, Config> config_map)
{
    video = new Video(config_map["video"]);
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