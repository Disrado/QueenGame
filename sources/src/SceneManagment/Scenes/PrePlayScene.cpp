#include "../../../include/SceneManagment/Scenes/PrePlayScene.hpp"

PrePlayScene::PrePlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

    createLabels(_windowSize);
    createOpponentTypeTab(_windowSize);
    createBoardSizeTab(_windowSize);
    createBotLvlTab(_windowSize);
    createStartBtn(_windowSize);
    createBackBtn(_windowSize);
}

PrePlayScene::~PrePlayScene()
{
    gui->remove(startBtn);
    gui->remove(backBtn);
    gui->remove(boardSizeTab);
    gui->remove(opponentTypeTab);
    gui->remove(botLvlTab);
}

void PrePlayScene::createLabels(const sf::Vector2u& _windowSize)
{
    opponentTypeLbl = std::make_shared<sf::Text>("Opponent type", *(ResourceManager::getInstance().getFont("KarnacOne")));
    opponentTypeLbl->setCharacterSize(_windowSize.y / 16);
    opponentTypeLbl->setOutlineThickness(3.0);
    opponentTypeLbl->setFillColor(sf::Color::Black);
    opponentTypeLbl->setOutlineColor(sf::Color::Red);
    opponentTypeLbl->setPosition(_windowSize.x / 2 - opponentTypeLbl->getLocalBounds().width - _windowSize.x / 60,
                                 _windowSize.y * 1/4);

    boardSizeLbl = std::make_shared<sf::Text>("Board Size", *(ResourceManager::getInstance().getFont("KarnacOne")));
    boardSizeLbl->setCharacterSize(_windowSize.y / 16);
    boardSizeLbl->setOutlineThickness(3.0);
    boardSizeLbl->setFillColor(sf::Color::Black);
    boardSizeLbl->setOutlineColor(sf::Color::Red);
    boardSizeLbl->setPosition(_windowSize.x / 2 - boardSizeLbl->getLocalBounds().width - _windowSize.x / 60,
                              opponentTypeLbl->getPosition().y + _windowSize.y / 8);

    botLvlLbl = std::make_shared<sf::Text>("Bot lvl", *(ResourceManager::getInstance().getFont("KarnacOne")));
    botLvlLbl->setCharacterSize(_windowSize.y / 16);
    botLvlLbl->setOutlineThickness(3.0);
    botLvlLbl->setFillColor(sf::Color::Black);
    botLvlLbl->setOutlineColor(sf::Color::Red);
    botLvlLbl->setPosition(_windowSize.x / 2 - botLvlLbl->getLocalBounds().width - _windowSize.x / 60,
                           boardSizeLbl->getPosition().y + _windowSize.y / 8);
}

void PrePlayScene::createOpponentTypeTab(const sf::Vector2u& _windowSize)
{
    opponentTypeTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    opponentTypeTab->insert(0, "Player", false);
    opponentTypeTab->insert(1, "  Bot ", false);
    
    if(Settings::getInstance().getOpponentType() == OpponentType::player)
        opponentTypeTab->select(0);
    else
        opponentTypeTab->select(1);

    opponentTypeTab->setTabHeight(_windowSize.y / 16);
    
    opponentTypeTab->setPosition(_windowSize.x / 2 + _windowSize.x / 60,
                                 opponentTypeLbl->getPosition().y + opponentTypeLbl->getLocalBounds().height / 4 );
    
    opponentTypeTab->connect("tabselected", [this, tab = opponentTypeTab] {
            Settings::getInstance().setOpponentType((tab->getSelected() == "Player") ? OpponentType::player : OpponentType::bot);
            if(tab->getSelected() == "Player") {
                botLvlLbl->setString("");
                botLvlTab->hide();
            } else {
                botLvlLbl->setString("Bot lvl");
                botLvlTab->show();  
            }});
    
     gui->add(opponentTypeTab);
}

void PrePlayScene::createBoardSizeTab(const sf::Vector2u& _windowSize)
{
    boardSizeTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    boardSizeTab->insert(0, " 4 ", false);
    boardSizeTab->insert(1, " 6 ", false);
    boardSizeTab->insert(2, " 8 ", false);
    boardSizeTab->insert(3, " 10 ", false);
    
    if(Settings::getInstance().getBoardSize() == 4)
        boardSizeTab->select(0);
    else if(Settings::getInstance().getBoardSize() == 6)
        boardSizeTab->select(1);
    else if(Settings::getInstance().getBoardSize() == 8)
        boardSizeTab->select(2);
    else
        boardSizeTab->select(3);

    boardSizeTab->setTabHeight(_windowSize.y / 16);
    
    boardSizeTab->setPosition(_windowSize.x / 2 + _windowSize.x / 60,
                              boardSizeLbl->getPosition().y +  + boardSizeLbl->getLocalBounds().height / 4);
    
    boardSizeTab->connect("tabselected", [tab = boardSizeTab] {
            Settings::getInstance().setBoardSize(std::stoi(tab->getSelected().toAnsiString())); });
    
    gui->add(boardSizeTab);
}

void PrePlayScene::createBotLvlTab(const sf::Vector2u& _windowSize)
{
    botLvlTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    botLvlTab->insert(0, "  Easy  ", false);
    botLvlTab->insert(1, " Medium ", false);
    botLvlTab->insert(2, "  Hard  ", false);

    botLvlTab->setTabHeight(_windowSize.y / 16);
    
    if(Settings::getInstance().getDifficultyLevel() == DifficultyLevel::Easy)
        botLvlTab->select(0);
    else if(Settings::getInstance().getDifficultyLevel() == DifficultyLevel::Medium)
        botLvlTab->select(1);
    else
        botLvlTab->select(2);
        
    botLvlTab->setPosition(_windowSize.x / 2 + _windowSize.x / 60,
                           botLvlLbl->getPosition().y + botLvlLbl->getLocalBounds().height / 4);
    
    botLvlTab->connect("tabselected", [tab = botLvlTab] {
            if(tab->getSelected() == "  Easy"  )
                Settings::getInstance().setDifficultyLevel(DifficultyLevel::Easy);
            else if(tab->getSelected() == " Medium ")
                Settings::getInstance().setDifficultyLevel(DifficultyLevel::Medium);
            else
                Settings::getInstance().setDifficultyLevel(DifficultyLevel::Hard); });
    
    gui->add(botLvlTab);
}

void PrePlayScene::createStartBtn(const sf::Vector2u& _windowSize)
{
    startBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    startBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    startBtn->setPosition(_windowSize.x - startBtn->getSize().x * 1.5,
                          _windowSize.y - startBtn->getSize().y * 2 );
    startBtn->setText("Start");
    startBtn->connect("mousereleased",[_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(startBtn);
}

void PrePlayScene::createBackBtn(const sf::Vector2u& _windowSize)
{
    backBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    backBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    backBtn->setText("Back");
    backBtn->setPosition(backBtn->getSize().x * 0.5, _windowSize.y - backBtn->getSize().y * 2);
    backBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(backBtn);
}

void PrePlayScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*opponentTypeLbl);
    _renderWindow->draw(*boardSizeLbl);
    _renderWindow->draw(*botLvlLbl);
    gui->draw();
}
