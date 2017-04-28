#include "EventHandler.hpp"

EventHandler::EventHandler(SceneManager* _smgr) : smgr(_smgr)
{}

void EventHandler::HandleMouseActions()
{
    auto mousePosition = sf::Mouse::getPosition();
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        handleRightMouseClick(mousePosition);
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        handleLeftMouseClick(mousePosition);
}

void EventHandler::handleRightMouseClick(sf::Vector2i& _mousePosition)
{
    auto playSmgr = smgr->getPlaySceneManager();
        
    if(playSmgr->moveQueen(_mousePosition))
        playSmgr->hightlightPossibleMoves();
}

void EventHandler::handleLeftMouseClick(sf::Vector2i& _mousePosition)
{
    switch (smgr->getCurrentScene()) {

    case Scenes::play: {
        auto playSmgr = smgr->getPlaySceneManager();
        break;
    }
        
    case Scenes::start: {
        auto startSmgr = smgr->getStartSceneManager();
        smgr->setCurrentScene(Scenes::play);
        break;
    }

    case Scenes::settings: {
        break;
    }
    }    
}
