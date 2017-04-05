#ifndef GAME_HPP
#define GAME_HPP

#include "EventHandler.hpp"
#include "../Graphics/PlayScene.hpp"

using namespace std;

class Game
{
private:
    sf::RenderWindow *app_window;
    PlayScene *playScene;
    EventHandler *eventHandler;
	
public:
    Game();
    ~Game();
    void startLoop();
};

#endif //GAME_HPP
