#ifndef GAME_HPP
#define GAME_HPP

#include "EventHandler.hpp"
#include "SceneManager.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

const string PATH_TO_PICTURES = "/home/nik/Sources/QueenGame/media/pictures/";

class Game
{
private:
    sf::RenderWindow *appWindow;
    SceneManager *smgr;
    EventHandler *eventHandler;
	
public:
    Game();
    ~Game();
    void startLoop();
};

#endif //GAME_HPP
