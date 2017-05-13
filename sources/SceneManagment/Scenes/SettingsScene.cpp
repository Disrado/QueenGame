#include "SettingsScene.hpp"

SettingsScene::SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("forest_background")));

    backBtn = tgui::Button::create();
    backBtn->setText("Back");
    backBtn->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                         (_windowSize.y / 2) - ( backBtn->getSize().y / 2) - 80);
    backBtn->connect("mousereleased", [_smgr](){ _smgr->backToPreviousScene(); });
    gui->add(backBtn);
    
    boardSizeTab = tgui::Tab::create();
    boardSizeTab->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                              (_windowSize.y / 2) - ( backBtn->getSize().y / 2) - 20);
    boardSizeTab->insert(0, "   6   ", false);
    boardSizeTab->insert(1, "   8   ", true);
    boardSizeTab->insert(2, "   10  ", false);
    boardSizeTab->connect("tabselected",
                          [tab = boardSizeTab] {
                              Settings::getInstance().setBoardSize(std::stoi(tab->getSelected().toAnsiString()));
                          });
    gui->add(boardSizeTab);
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
