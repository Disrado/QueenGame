#include "StartScene.hpp"

StartScene::StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("blue_background")));

    playBtn = tgui::Button::create();
    playBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 80);
    playBtn->setText("Play");
    playBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(playBtn);

    settingsBtn = tgui::Button::create();
    settingsBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                             (_windowSize.y / 2));
    settingsBtn->setText("Settings");
    settingsBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Settings) ;});
    gui->add(settingsBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) + 80);
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [=](){ exit(0); });
    gui->add(exitBtn);
}

StartScene::~StartScene()
{
    gui->removeAllWidgets();
}

void StartScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
