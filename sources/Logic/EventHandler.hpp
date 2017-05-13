#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "../SceneManagment/SceneManager.hpp"
#include "../SceneManagment/Scenes/PlayScene.hpp"
#include "../PlayersSystem/PlayArbiter.hpp"

class EventHandler
{
private:
    SceneManager* smgr;
    PlayArbiter* arbiter;
    
public:
    EventHandler(SceneManager* _smgr, PlayArbiter* _arbiter);
    void HandleUserActions(sf::Event& event);
};

#endif //EVENTHANDLER_HPP

