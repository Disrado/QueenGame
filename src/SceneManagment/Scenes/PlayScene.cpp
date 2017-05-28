#include "../../../include/SceneManagment/Scenes/PlayScene.hpp"

PlayScene::PlayScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
    : Scene(_smgr, _gui)
{
    background = std::make_shared<sf::Sprite>(*(ResourceManager::getInstance().getTexture("ChessBattle")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);
    background->setColor(sf::Color(254, 254, 254, 180));
        
    board = new Board(_windowSize, Settings::getInstance().getBoardSize());
    queen = new Queen(board);
    playArbiter = new PlayArbiter(_smgr, queen);
    
    createPauseBtn(_windowSize);
    createFirstPlayerName(_windowSize);
    createSecondPlayerName(_windowSize);
    createFirstPlayerScore(_windowSize);
    createSecondPlayerScore(_windowSize);

    MusicPlayer::getInstance().play();
}

PlayScene::~PlayScene()
{
    MusicPlayer::getInstance().reset();
    MusicPlayer::getInstance().pause();

    delete firstPlayerName;
    delete secondPlayerName;
    delete firstPlayerScore;
    delete secondPlayerScore;
    delete playArbiter;
    delete board;
    delete queen;

    gui->remove(pauseBtn);
}

void PlayScene::createPauseBtn(const sf::Vector2u& _windowSize)
{
    pauseBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    pauseBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    pauseBtn->setPosition(_windowSize.x - pauseBtn->getSize().x * 1.5,
                          _windowSize.y - pauseBtn->getSize().y * 1.5);
    pauseBtn->setText("Pause");
    pauseBtn->connect("mousereleased",[_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Pause); });
    gui->add(pauseBtn);
}

void PlayScene::createSecondPlayerScore(const sf::Vector2u& _windowSize)
{
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

void PlayScene::createFirstPlayerScore(const sf::Vector2u& _windowSize)
{
    firstPlayerScore = new sf::Text("0000", *(ResourceManager::getInstance().getFont("KarnacOne")));
    firstPlayerScore->setCharacterSize(_windowSize.y / 10);
    firstPlayerScore->setOutlineThickness(3.0);
    firstPlayerScore->setFillColor(sf::Color::Black);
    firstPlayerScore->setOutlineColor(sf::Color::Red);
    firstPlayerScore->setPosition(firstPlayerName->getPosition().x +
                                  firstPlayerName->getLocalBounds().width / 2 -
                                  firstPlayerScore->getLocalBounds().width / 2,
                                  firstPlayerName->getPosition().y + firstPlayerScore->getLocalBounds().height * 2);
}

void PlayScene::createFirstPlayerName(const sf::Vector2u& _windowSize)
{
    firstPlayerName = new sf::Text("Player 1", *(ResourceManager::getInstance().getFont("KarnacOne")));
    firstPlayerName->setCharacterSize(_windowSize.y / 10);
    firstPlayerName->setOutlineThickness(3.0);
    firstPlayerName->setFillColor(sf::Color::Black);
    firstPlayerName->setOutlineColor(sf::Color::Red);
    firstPlayerName->setPosition((_windowSize.x / 50 ), _windowSize.y * 5/9);
}

void PlayScene::createSecondPlayerName(const sf::Vector2u& _windowSize)
{
    secondPlayerName = new sf::Text((Settings::getInstance().getOpponentType() == OpponentType::bot) ? "Bot" : "Player 2",
                                    *(ResourceManager::getInstance().getFont("KarnacOne")));
    secondPlayerName->setCharacterSize(_windowSize.y / 10);
    secondPlayerName->setOutlineThickness(3.0);
    secondPlayerName->setFillColor(sf::Color::Black);
    secondPlayerName->setOutlineColor(sf::Color::Red);
    secondPlayerName->setPosition(_windowSize.x - (_windowSize.x / 50 ) - firstPlayerName->getLocalBounds().width -
                                  (secondPlayerName->getLocalBounds().width - firstPlayerName->getLocalBounds().width) / 2,
                                  _windowSize.y * 5/9);
}
    
void PlayScene::hideGui()
{
    pauseBtn->hide();
}

void PlayScene::unhideGui()
{
    pauseBtn->show();
}

void PlayScene::hightlightCells()
{
    if(Settings::getInstance().isHelpEnabled())
        board->hightlightPossibleMoves(queen->getAvailableCells(queen->getPosition()));
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

Board* PlayScene::getBoard() const
{
    return board;
}

Queen* PlayScene::getQueen() const
{
    return queen;
}

PlayArbiter* PlayScene::getPlayArbiter() const
{
    return playArbiter;
}

void PlayScene::update()
{
	playArbiter->update();
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
