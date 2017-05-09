#include "StartScene.hpp"

StartScene::StartScene(const sf::Vector2u& _windowSize,
                       tgui::Gui *_gui,
                       SceneManager* _smgr)
{
    background = new sf::Sprite(*(TextureLoader::Instance().getItem("blue_background")));

    playBtn = tgui::Button::create();
    playBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - ( playBtn->getSize().y / 2) - 80);
    playBtn->setText("Play");
    playBtn->connect("pressed", [=](){ _smgr->setCurrentScene(Scenes::play); });
    _gui->add(playBtn);

    settingsBtn = tgui::Button::create();
    settingsBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                             (_windowSize.y / 2) - ( playBtn->getSize().y / 2));
    settingsBtn->setText("Settings");
    _gui->add(settingsBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - ( playBtn->getSize().y / 2) + 80);
    exitBtn->setText("Exit");
    exitBtn->connect("pressed", [=](){ exit(0); });
    _gui->add(exitBtn);
}

tgui::Button* StartScene::getPlayButton()
{
    return playBtn.get();
}

void StartScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
}
