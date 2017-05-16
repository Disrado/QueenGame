#include "StartScene.hpp"

StartScene::StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));

    tgui::Theme::Ptr theme = tgui::Theme::create("../GUITheme/Black.txt");
        
    playBtn = theme->load("Button");
    playBtn->setSize(200, 80);
    playBtn->setPosition((_windowSize.x / 2) - (playBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 100);
    playBtn->setText("Play");
    playBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::PrePlay); });
    gui->add(playBtn);

    settingsBtn = theme->load("Button");
    settingsBtn->setSize(200, 80);
    settingsBtn->setPosition((_windowSize.x / 2) - (settingsBtn->getSize().x / 2),
                             (_windowSize.y / 2));
    settingsBtn->setText("Settings");
    settingsBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Settings) ;});
    gui->add(settingsBtn);

    exitBtn = theme->load("Button");
    exitBtn->setSize(200, 80);
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2) + 100);
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
