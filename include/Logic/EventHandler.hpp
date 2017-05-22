#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "../SceneManagment/Scenes/PlayScene.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../PlayersSystem/PlayArbiter.hpp"

class EventHandler
{
private:
    SceneManager* smgr;
    
public:
    EventHandler(SceneManager* _smgr);
    void HandleUserActions(sf::Event& event);
};

#endif //EVENTHANDLER_HPP

