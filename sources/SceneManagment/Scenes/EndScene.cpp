#include "EndScene.hpp"

EndScene::EndScene(const sf::Vector2u& _windowSize,
                   tgui::Gui* _gui,
                   SceneManager* _smgr,
                   const std::string& _winnerName,
                   const int _winnerScore) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));

    createWinnerNameLbl(_windowSize, _winnerName);
    createWinnerScoreLbl(_windowSize, _winnerScore);
    createPlayAgainBtn(_windowSize);
    createExitBtn(_windowSize);
}

EndScene::~EndScene()
{
    gui->remove(playAgainBtn);
    gui->remove(exitBtn);
}

void EndScene::createWinnerNameLbl(const sf::Vector2u& _windowSize,
                                   const std::string& _winnerName)
{
    winnerNameLbl = new sf::Text((_winnerName == "") ? "Draw" : "Winner: " + _winnerName,
                                 *(ResourceManager::getInstance().getFont("KarnacOne")));
    winnerNameLbl->setCharacterSize(_windowSize.y / 10);
    winnerNameLbl->setOutlineThickness(3.0);
    winnerNameLbl->setFillColor(sf::Color::Black);
    winnerNameLbl->setOutlineColor(sf::Color::Red);
    winnerNameLbl->setPosition(_windowSize.x / 2 - winnerNameLbl->getLocalBounds().width / 2, _windowSize.y / 2 - _windowSize.y / 13);
}

void EndScene::createWinnerScoreLbl(const sf::Vector2u& _windowSize,
                                    const int _winnerScore)
{
    winnerScoreLbl = new sf::Text("Score: " + std::to_string(_winnerScore),
                                 *(ResourceManager::getInstance().getFont("KarnacOne")));
    winnerScoreLbl->setCharacterSize(_windowSize.y / 10);
    winnerScoreLbl->setOutlineThickness(3.0);
    winnerScoreLbl->setFillColor(sf::Color::Black);
    winnerScoreLbl->setOutlineColor(sf::Color::Red);
    winnerScoreLbl->setPosition(_windowSize.x / 2 - winnerScoreLbl->getLocalBounds().width / 2,
                                winnerNameLbl->getPosition().y + _windowSize.y / 9);
}

void EndScene::createPlayAgainBtn(const sf::Vector2u& _windowSize)
{
    playAgainBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    playAgainBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    playAgainBtn->setPosition(_windowSize.x / 2 - playAgainBtn->getSize().x * 2.5,
                              winnerScoreLbl->getPosition().y + playAgainBtn->getSize().y * 2);
    playAgainBtn->setText("Play Again");
    playAgainBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::PrePlay); });
    gui->add(playAgainBtn);
}

void EndScene::createExitBtn(const sf::Vector2u& _windowSize)
{
    exitBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    exitBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    exitBtn->setPosition(_windowSize.x / 2 + exitBtn->getSize().x * 1.5,
                         winnerScoreLbl->getPosition().y + exitBtn->getSize().y * 2);
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

void EndScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*winnerNameLbl);
    _renderWindow->draw(*winnerScoreLbl);
    gui->draw();
}

