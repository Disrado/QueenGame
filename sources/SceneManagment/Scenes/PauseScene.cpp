#include "PauseScene.hpp"

PauseScene::PauseScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background_art")));

    resumeBtn = tgui::Button::create();
    resumeBtn->setPosition((_windowSize.x / 2) - (resumeBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 40);
    resumeBtn->setText("Resume");
    resumeBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(resumeBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2));
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [=](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

PauseScene::~PauseScene()
{
    gui->removeAllWidgets();
}

void PauseScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
