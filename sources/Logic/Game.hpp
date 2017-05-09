#ifndef GAME_HPP
#define GAME_HPP

#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include "EventHandler.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

const string PATH_TO_PICTURES = "/home/nik/Sources/QueenGame/media/pictures/";

class Game
{
private:
    sf::RenderWindow *appWindow;
    tgui::Gui *gui;
    SceneManager *smgr;
    EventHandler *eventHandler;
	
public:
    Game();
    ~Game();
    void startLoop();
};

#endif //GAME_HPP
