#include "../../include/Logic/EventHandler.hpp"

EventHandler::EventHandler(SceneManager* _smgr) : smgr(_smgr)
{}

void EventHandler::HandleUserActions(sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed) {
        if(smgr->getPlayScene() && smgr->getCurrentSceneType() == Scenes::Play) {
            smgr->getPlayScene()->getPlayArbiter()->turn(sf::Vector2f(sf::Mouse::getPosition()));
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            smgr->replaceCurrentScene(Scenes::Pause);
    }
}

