#include "EndScene.hpp"

EndScene::EndScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    
    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2));
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [=](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

EndScene::~EndScene()
{
    gui->removeAllWidgets();
}

void EndScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}

