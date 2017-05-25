#ifndef GAME_HPP
#define GAME_HPP

#include "../GameSystem/ResourceManager.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../Logic/PlayersSystem/PlayArbiter.hpp"
#include "EventHandler.hpp"

const string PATH_TO_GUI_THEME = "../media/GUITheme/Black.txt";
const string PATH_TO_PICTURES = "../media/pictures/";
const string PATH_TO_FONTS = "../media/fonts/";

class Game
{
private:
    sf::RenderWindow *renderWindow;
    tgui::Gui *gui;
    SceneManager *smgr;
    EventHandler *eventHandler;
	
public:
    Game();
    ~Game();
    void startLoop();
};

#endif //GAME_HPP
