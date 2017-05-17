#include "StartScene.hpp"

StartScene::StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

    createSettingsButtons(_windowSize);
    createPlayButton(_windowSize);
    createExitButton(_windowSize);
}

void StartScene::createSettingsButtons(const sf::Vector2u& _windowSize)
{
    settingsBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    settingsBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    settingsBtn->setPosition((_windowSize.x / 2) - (settingsBtn->getSize().x / 2),
                             (_windowSize.y / 2));
    settingsBtn->setText("Settings");
    settingsBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Settings) ;});
    gui->add(settingsBtn);
}

void StartScene::createPlayButton(const sf::Vector2u& _windowSize)
{
    playBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    playBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    playBtn->setPosition((_windowSize.x / 2) - playBtn->getSize().x / 2,
                         (_windowSize.y / 2) - (playBtn->getSize().y * 1.5));
    playBtn->setText("Play");
    playBtn->connect("mousereleased",[_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::PrePlay); });
    gui->add(playBtn);
}

void StartScene::createExitButton(const sf::Vector2u& _windowSize)
{
    exitBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    exitBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2) + (playBtn->getSize().y * 1.5));
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [](){ exit(0); });
    gui->add(exitBtn);
}

StartScene::~StartScene()
{
    gui->remove(settingsBtn);
    gui->remove(playBtn);
    gui->remove(exitBtn);
}

void StartScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
