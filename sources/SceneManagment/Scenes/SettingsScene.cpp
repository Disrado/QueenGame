#include "SettingsScene.hpp"

SettingsScene::SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

    createBackButton(_windowSize);
    createHelpSwitchTab(_windowSize);
}

void SettingsScene::createBackButton(const sf::Vector2u& _windowSize)
{
    backBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    backBtn->setText("Back");
    backBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    backBtn->setPosition(backBtn->getSize().x * 0.5, _windowSize.y - backBtn->getSize().y * 2);
    backBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(backBtn);
}

void SettingsScene::createHelpSwitchTab(const sf::Vector2u& _windowSize)
{
        //--------------------HelpSwitchTab--------------------
    helpSwitchTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    helpSwitchTab->insert(0, " On ", false);
    helpSwitchTab->insert(1, " Off ", false);
    helpSwitchTab->setSize(300, 50);
    helpSwitchTab->setPosition(_windowSize.x / 2, _windowSize.y / 2 - 80);
    
    if(Settings::getInstance().isHelpEnabled())
        helpSwitchTab->select(0);
    else
        helpSwitchTab->select(1);
  
    helpSwitchTab->connect("tabselected",
                           [tab = helpSwitchTab] { (tab->getSelected() == " On ") ?
                                   Settings::getInstance().enableTurnHelp() :
                                   Settings::getInstance().disableTurnHelp(); });
    gui->add(helpSwitchTab);
}

SettingsScene::~SettingsScene()
{
    gui->remove(helpSwitchTab);
    gui->remove(backBtn);
}

void SettingsScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
