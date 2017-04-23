#ifndef GAME_HPP
#define GAME_HPP

#include "EventHandler.hpp"
#include "SceneManager.hpp"

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
