#include "SettingsScene.hpp"

SettingsScene::SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

    tgui::Theme::Ptr theme = tgui::Theme::create("../GUITheme/Black.txt");
    //--------------------HelpSwitchTab--------------------
    helpSwitchTab = theme->load("Tab");
    helpSwitchTab->insert(0, " On ", false);
    helpSwitchTab->insert(1, " Off ", false);
    helpSwitchTab->setSize(300, 50);
    helpSwitchTab->setPosition(_windowSize.x / 2, _windowSize.y / 2 - 80);
    
    if(Settings::getInstance().helpIsEnabled())
        helpSwitchTab->select(0);
    else
        helpSwitchTab->select(1);
  
    helpSwitchTab->connect("tabselected",
                           [tab = helpSwitchTab] { (tab->getSelected() == " On ") ?
                                   Settings::getInstance().enableTurnHelp() :
                                   Settings::getInstance().disableTurnHelp(); });
    gui->add(helpSwitchTab);

    //--------------------BackButton--------------------
    backBtn = theme->load("Button");
    backBtn->setText("Back");
    backBtn->setSize(150, 50);
    backBtn->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                         (_windowSize.y / 2) + 40);
    backBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(backBtn);
}

SettingsScene::~SettingsScene()
{
    gui->removeAllWidgets();
}

void SettingsScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
