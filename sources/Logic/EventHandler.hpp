#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "../SceneManagment/SceneManager.hpp"

class EventHandler
{
private:
    SceneManager* smgr;

private:
    void handleRightMouseClick(sf::Vector2i& _mousePosition);
    void handleLeftMouseClick(sf::Vector2i& _mousePosition);
    
public:
    EventHandler(SceneManager* _smgr);
    void HandleMouseActions();
};

#endif //EVENTHANDLER_HPP
