#include "SettingsScene.hpp"

SettingsScene::SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));

    //--------------------HelpSwitchTab--------------------
    helpSwitchTab = tgui::Tab::create();
    helpSwitchTab->insert(0, " On ", false);
    helpSwitchTab->insert(1, " Off ", false);
    
    if(Settings::getInstance().helpIsEnabled())
        helpSwitchTab->select(0);
    else
        helpSwitchTab->select(1);
    
    helpSwitchTab->setPosition((_windowSize.x / 2) - (helpSwitchTab->getSize().x / 2),
                              (_windowSize.y / 2) + 40);
    helpSwitchTab->connect("tabselected",
                           [tab = helpSwitchTab] { (tab->getSelected() == " On ") ?
                                   Settings::getInstance().enableTurnHelp() :
                                   Settings::getInstance().disableTurnHelp(); });
    gui->add(helpSwitchTab);

    //--------------------BackButton--------------------
    backBtn = tgui::Button::create();
    backBtn->setText("Back");
    backBtn->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 80);
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
