#include "PlayScene.hpp"

PlayScene::PlayScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("forest_background")));
    
    board = new Board(Settings::getInstance().getBoardSize());
    board->createBoard(_windowSize);
    
    queen = new Queen(ResourceManager::getInstance().getTexture("queen"));
    queen->setSpawnPoint(board->getQueenSpawnCell());

    firstPlayerName = new sf::Text("Player 1", *(ResourceManager::getInstance().getFont("RobotoMonoBoldItalic")));
    firstPlayerName->setPosition(_windowSize.x - (_windowSize.x - 40), 150);
    secondPlayerName = new sf::Text((Settings::getInstance().getOpponentType() == OpponentType::bot) ? "Bot" : "Player 2",
                                    *(ResourceManager::getInstance().getFont("RobotoMonoBoldItalic")));    
    secondPlayerName->setPosition(_windowSize.x - 40 - secondPlayerName->getLocalBounds().width, 150);
    
    firstPlayerScore = new sf::Text("0000", *(ResourceManager::getInstance().getFont("RobotoMonoBoldItalic")));
    firstPlayerScore->setPosition(firstPlayerName->getPosition().x +
                                  firstPlayerName->getLocalBounds().width / 2 -
                                  firstPlayerScore->getLocalBounds().width / 2,
                                  firstPlayerName->getPosition().y + firstPlayerScore->getLocalBounds().height * 2);
    secondPlayerScore = new sf::Text("0000", *(ResourceManager::getInstance().getFont("RobotoMonoBoldItalic")));
    secondPlayerScore->setPosition(secondPlayerName->getPosition().x +
                                   secondPlayerName->getLocalBounds().width / 2 -
                                   secondPlayerScore->getLocalBounds().width / 2,
                                   secondPlayerName->getPosition().y + secondPlayerScore->getLocalBounds().height * 2);
    
    hightlightPossibleMoves();
}

PlayScene::~PlayScene()
{
    delete firstPlayerName;
    delete secondPlayerName;
    delete firstPlayerScore;
    delete secondPlayerScore;
    delete board;
    delete queen;
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

int PlayScene::moveQueen(sf::Vector2i _newPosition)
{
    auto cellArray = board->getCells();
    
    for(auto &line : cellArray)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(queen->canMove(cell))
                    queen->move(cell);

    this->hightlightPossibleMoves();
    return queen->getConqueredPoints();
}

void PlayScene::hightlightPossibleMoves()
{
    auto cellArray = board->getCells();
    
    for(auto &line : cellArray)
        for(auto &cell : line)
            if(queen->canMove(cell))
                cell->showFrame();
            else
                cell->disableFrame();
}

void PlayScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*firstPlayerName);
    _renderWindow->draw(*firstPlayerScore);
    _renderWindow->draw(*secondPlayerName);
    _renderWindow->draw(*secondPlayerScore);
    board->draw(_renderWindow);
    queen->draw(_renderWindow);
    gui->draw();
}
