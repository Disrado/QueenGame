#include "PauseScene.hpp"

PauseScene::PauseScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("forest_background")));

    resumeBtn = tgui::Button::create();
    resumeBtn->setPosition((_windowSize.x / 2) - (resumeBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 75);
    resumeBtn->setText("Resume");
    resumeBtn->connect("mousereleased",[_smgr](){ _smgr->backToPreviousScene(); });
    gui->add(resumeBtn);

    settingsBtn = tgui::Button::create();
    settingsBtn->setPosition((_windowSize.x / 2) - (settingsBtn->getSize().x / 2),
                             (_windowSize.y / 2) - 25);
    settingsBtn->setText("Settings");
    settingsBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Settings) ;});
    gui->add(settingsBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2) + 25);
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [=](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);

    exitBtn = tgui::Button::create();
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2) + 75);
    exitBtn->setText("Exit game");
    exitBtn->connect("mousereleased", [=](){ exit(0); });
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
