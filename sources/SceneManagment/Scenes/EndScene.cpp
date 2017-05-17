#include "EndScene.hpp"

EndScene::EndScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    
    createPlayAgainBtn(_windowSize);
    createExitBtn(_windowSize);
}

EndScene::~EndScene()
{
    gui->remove(playAgainBtn);
    gui->remove(exitBtn);
}

void EndScene::createPlayAgainBtn(const sf::Vector2u& _windowSize)
{
    playAgainBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    playAgainBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    playAgainBtn->setPosition((_windowSize.x / 2) - (playAgainBtn->getSize().x / 2),
                         (_windowSize.y / 2));
    playAgainBtn->setText("Play Again");
    playAgainBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(playAgainBtn);
}

void EndScene::createExitBtn(const sf::Vector2u& _windowSize)
{
    exitBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    playAgainBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2));
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

void EndScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}

