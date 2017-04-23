#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "SceneManager.hpp"

class EventHandler
{
private:
    SceneManager* smgr;
    
public:
    EventHandler(SceneManager* _smgr);
    void HandleMouseActions();
};

#endif //EVENTHANDLER_HPP
