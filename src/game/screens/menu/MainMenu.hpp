#ifndef MAINMENU_H_DEFINED
#define MAINMENU_H_DEFINED

#include "../../../engine/screens/menu/MenuScreen.hpp"


class MainMenu : public MenuScreen
{
    public:
        void run();
        void newItem(); 

};

#endif /* MAINMENU_H_DEFINED */