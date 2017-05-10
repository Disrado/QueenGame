#include "EventHandler.hpp"

EventHandler::EventHandler(SceneManager* _smgr) : smgr(_smgr)
{}

void EventHandler::HandleUserActions()
{
    auto mousePosition = sf::Mouse::getPosition();
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        if(auto playScene = smgr->getPlayScene())
            if(playScene->moveQueen(mousePosition))
                playScene->hightlightPossibleMoves();
    }
}
