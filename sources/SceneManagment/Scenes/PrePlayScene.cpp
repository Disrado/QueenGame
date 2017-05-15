#include "PrePlayScene.hpp"

PrePlayScene::PrePlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    
    startBtn = tgui::Button::create();
    startBtn->setPosition((_windowSize.x / 2) - (startBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 80);
    startBtn->setText("Start");
    startBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(startBtn);

    backBtn = tgui::Button::create();
    backBtn->setText("Back");
    backBtn->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                         (_windowSize.y / 2) - 40);
    backBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(backBtn);
    
    boardSizeTab = tgui::Tab::create();
    boardSizeTab->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                              (_windowSize.y / 2) + 40);
    boardSizeTab->insert(0, "   6   ", false);
    boardSizeTab->insert(1, "   8   ", true);
    boardSizeTab->insert(2, "   10  ", false);
    boardSizeTab->connect("tabselected",
                          [tab = boardSizeTab] {
                              Settings::getInstance().setBoardSize(std::stoi(tab->getSelected().toAnsiString()));
                          });
    gui->add(boardSizeTab);

    boardSizeTab = tgui::Tab::create();
    boardSizeTab->setPosition((_windowSize.x / 2) - (backBtn->getSize().x / 2),
                              (_windowSize.y / 2) + 80);
    boardSizeTab->insert(0, " Player ", true);
    boardSizeTab->insert(1, "   Bot  ", false);
    boardSizeTab->connect("tabselected",
                          [tab = boardSizeTab] {
                              Settings::getInstance().setOpponentType(OpponentType::player);
                          });
    gui->add(boardSizeTab);
}

PrePlayScene::~PrePlayScene()
{
    gui->removeAllWidgets();
}

void PrePlayScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
