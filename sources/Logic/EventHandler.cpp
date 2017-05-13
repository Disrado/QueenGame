#include "EventHandler.hpp"

EventHandler::EventHandler(SceneManager* _smgr, PlayArbiter* _arbiter) : smgr(_smgr), arbiter(_arbiter)
{}

void EventHandler::HandleUserActions(sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed) {
        if(smgr->getPlayScene()) {
                arbiter->turn(sf::Mouse::getPosition());
        }
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        //        if(smgr->getPlayScene()) {
            smgr->replaceCurrentScene(Scenes::Pause);
            //}
    }
}

