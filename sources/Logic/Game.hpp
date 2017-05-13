#ifndef GAME_HPP
#define GAME_HPP

#include "../ResourceManagment/ResourceManager.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../PlayersSystem/PlayArbiter.hpp"
#include "EventHandler.hpp"

const string PATH_TO_PICTURES = "../media/pictures/";
const string PATH_TO_FONTS = "../media/fonts/";

class Game
{
private:
    sf::RenderWindow *appWindow;
    tgui::Gui *gui;
    SceneManager *smgr;
    PlayArbiter* arbiter;
    EventHandler *eventHandler;
	
public:
    Game();
    ~Game();
    void startLoop();
};

#endif //GAME_HPP
