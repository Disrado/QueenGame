#include "../../../include/SceneManagment/Scenes/SettingsScene.hpp"

SettingsScene::SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

    createLabels(_windowSize);
    createMusicSwitchTab(_windowSize);
    createHelpSwitchTab(_windowSize);
    createBackButton(_windowSize);
}

SettingsScene::~SettingsScene()
{
    gui->remove(musicSwitchTab);
    gui->remove(helpSwitchTab);
    gui->remove(backBtn);
}

void SettingsScene::createLabels(const sf::Vector2u& _windowSize)
{
    helpLbl = std::make_shared<sf::Text>("Hightlight moves", *(ResourceManager::getInstance().getFont("KarnacOne")));
    helpLbl->setCharacterSize(_windowSize.y / 16);
    helpLbl->setOutlineThickness(3.0);
    helpLbl->setFillColor(sf::Color::Black);
    helpLbl->setOutlineColor(sf::Color::Red);
    helpLbl->setPosition(_windowSize.x / 2 - helpLbl->getLocalBounds().width - _windowSize.x / 60,
                         _windowSize.y * 1/4);

    musicLbl = std::make_shared<sf::Text>("Music", *(ResourceManager::getInstance().getFont("KarnacOne")));
    musicLbl->setCharacterSize(_windowSize.y / 16);
    musicLbl->setOutlineThickness(3.0);
    musicLbl->setFillColor(sf::Color::Black);
    musicLbl->setOutlineColor(sf::Color::Red);
    musicLbl->setPosition(_windowSize.x / 2 - musicLbl->getLocalBounds().width - _windowSize.x / 60,
                          helpLbl->getPosition().y + _windowSize.y / 8);
}

void SettingsScene::createHelpSwitchTab(const sf::Vector2u& _windowSize)
{
    helpSwitchTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    helpSwitchTab->insert(0, " On ", false);
    helpSwitchTab->insert(1, " Off ", false);

    if(Settings::getInstance().isHelpEnabled())
        helpSwitchTab->select(0);
    else
        helpSwitchTab->select(1);
    
    helpSwitchTab->setTabHeight(_windowSize.y / 16);    
    helpSwitchTab->setPosition(_windowSize.x / 2 + _windowSize.x / 60,
                                 helpLbl->getPosition().y + helpLbl->getLocalBounds().height / 4 );
  
    helpSwitchTab->connect("tabselected",
                           [tab = helpSwitchTab] { (tab->getSelected() == " On ") ?
                                   Settings::getInstance().enableTurnHelp() :
                                   Settings::getInstance().disableTurnHelp(); });
    gui->add(helpSwitchTab);
}

void SettingsScene::createMusicSwitchTab(const sf::Vector2u& _windowSize)
{
    musicSwitchTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    musicSwitchTab->insert(0, " On ", false);
    musicSwitchTab->insert(1, " Off ", false);

    if(Settings::getInstance().isMusicEnabled())
        musicSwitchTab->select(0);
    else
        musicSwitchTab->select(1);
    
    musicSwitchTab->setTabHeight(_windowSize.y / 16);    
    musicSwitchTab->setPosition(_windowSize.x / 2 + _windowSize.x / 60,
                                 musicLbl->getPosition().y + musicLbl->getLocalBounds().height / 4 );
  
    musicSwitchTab->connect("tabselected",
                           [tab = musicSwitchTab] { (tab->getSelected() == " On ") ?
                                   Settings::getInstance().enableMusic() : 
                                   Settings::getInstance().disableMusic(); });
    gui->add(musicSwitchTab);
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

void SettingsScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*helpLbl);
    _renderWindow->draw(*musicLbl);
    gui->draw();
}
