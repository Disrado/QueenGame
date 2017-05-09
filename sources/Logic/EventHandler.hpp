#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "../SceneManagment/SceneManager.hpp"
#include "../Scenes/PlayScene.hpp"

class EventHandler
{
private:
    SceneManager* smgr;
    
public:
    EventHandler(SceneManager* _smgr);
    void HandleUserActions();
};

#endif //EVENTHANDLER_HPP
