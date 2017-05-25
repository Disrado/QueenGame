#ifndef GAME_HPP
#define GAME_HPP

#include "../Logic/PlayersSystem/PlayArbiter.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../GameSystem/ResourceManager.hpp"
#include "../GameSystem/MusicPlayer.hpp"
#include "../GameSystem/Settings.hpp"
#include "EventHandler.hpp"

const std::string PATH_TO_GUI_THEME = "../media/GUITheme/Black.txt";
const std::string PATH_TO_PICTURES = "../media/pictures/";
const std::string PATH_TO_MUSIC = "../media/music/";
const std::string PATH_TO_FONTS = "../media/fonts/";

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
    void start();
};

#endif //GAME_HPP
