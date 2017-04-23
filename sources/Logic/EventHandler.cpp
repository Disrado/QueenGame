#include "EventHandler.hpp"

EventHandler::EventHandler(SceneManager* _smgr) : smgr(_smgr)
{}

void EventHandler::HandleMouseActions()
{
    auto mousePosition = sf::Mouse::getPosition();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        smgr->handleMouseClick(mousePosition);
}
