#include "PlayScene.hpp"

PlayScene::PlayScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("ChessBattle")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);
    background->setColor(sf::Color(254, 254, 254, 180));
    
    playArbiter = new PlayArbiter(this);
    
    board = new Board(_windowSize, Settings::getInstance().getBoardSize());
    
    firstPlayerName = new sf::Text("Player 1", *(ResourceManager::getInstance().getFont("KarnacOne")));
    firstPlayerName->setCharacterSize(_windowSize.y / 10);
    firstPlayerName->setPosition(_windowSize.x - (_windowSize.x - 40), _windowSize.y * 2/3);
    firstPlayerName->setOutlineThickness(3.0);
    firstPlayerName->setFillColor(sf::Color::Black);
    firstPlayerName->setOutlineColor(sf::Color::Red);
    
    secondPlayerName = new sf::Text((Settings::getInstance().getOpponentType() == OpponentType::bot) ? "Bot" : "Player 2",
                                    *(ResourceManager::getInstance().getFont("KarnacOne")));
    secondPlayerName->setCharacterSize(_windowSize.y / 10);
    secondPlayerName->setOutlineThickness(3.0);
    secondPlayerName->setFillColor(sf::Color::Black);
    secondPlayerName->setOutlineColor(sf::Color::Red);
    secondPlayerName->setPosition(_windowSize.x - 40 - secondPlayerName->getLocalBounds().width, _windowSize.y * 2/3);
    
    firstPlayerScore = new sf::Text("0000", *(ResourceManager::getInstance().getFont("KarnacOne")));
    firstPlayerScore->setCharacterSize(_windowSize.y / 10);
    firstPlayerScore->setOutlineThickness(3.0);
    firstPlayerScore->setFillColor(sf::Color::Black);
    firstPlayerScore->setOutlineColor(sf::Color::Red);
    firstPlayerScore->setPosition(firstPlayerName->getPosition().x +
                                  firstPlayerName->getLocalBounds().width / 2 -
                                  firstPlayerScore->getLocalBounds().width / 2,
                                  firstPlayerName->getPosition().y + firstPlayerScore->getLocalBounds().height * 2);
    
    secondPlayerScore = new sf::Text("0000", *(ResourceManager::getInstance().getFont("KarnacOne")));
    secondPlayerScore->setCharacterSize(_windowSize.y / 10);
    secondPlayerScore->setOutlineThickness(3.0);
    secondPlayerScore->setFillColor(sf::Color::Black);
    secondPlayerScore->setOutlineColor(sf::Color::Red);
    secondPlayerScore->setPosition(secondPlayerName->getPosition().x +
                                   secondPlayerName->getLocalBounds().width / 2 -
                                   secondPlayerScore->getLocalBounds().width / 2,
                                   secondPlayerName->getPosition().y + secondPlayerScore->getLocalBounds().height * 2);
}

PlayScene::~PlayScene()
{
    delete firstPlayerName;
    delete secondPlayerName;
    delete firstPlayerScore;
    delete secondPlayerScore;
    delete playArbiter;
    delete board;
}

void PlayScene::setFirstPlayerScore(int _score)
{
    std::string score = std::to_string(_score);
    while(score.size() < 4)
        score = "0" + score;
    
    firstPlayerScore->setString(score);
}

void PlayScene::setSecondPlayerScore(int _score)
{
    std::string score = std::to_string(_score);
    while(score.size() < 4)
        score = "0" + score;
    
    secondPlayerScore->setString(score);
}

Board* PlayScene::getBoard()
{
    return board;
}

PlayArbiter* PlayScene::getPlayArbiter()
{
    return playArbiter;
}

void PlayScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*firstPlayerName);
    _renderWindow->draw(*firstPlayerScore);
    _renderWindow->draw(*secondPlayerName);
    _renderWindow->draw(*secondPlayerScore);
    board->draw(_renderWindow);
    gui->draw();
}
