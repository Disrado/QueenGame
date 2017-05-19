#include "../../../include/SceneManagment/Scenes/PrePlayScene.hpp"

PrePlayScene::PrePlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));
    background->setScale(_windowSize.x / background->getLocalBounds().width,
                         _windowSize.y / background->getLocalBounds().height);

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

void PrePlayScene::createOpponentTypeTab(const sf::Vector2u& _windowSize)
{
    opponentTypeTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    opponentTypeTab->insert(0, "Player", false);
    opponentTypeTab->insert(1, "  Bot ", false);
    
    if(Settings::getInstance().getOpponentType() == OpponentType::player)
        opponentTypeTab->select(0);
    else
        opponentTypeTab->select(1);
    
    opponentTypeTab->setPosition((_windowSize.x / 2), (_windowSize.y / 2) + 80);
    opponentTypeTab->connect("tabselected", [tab = opponentTypeTab] {
            Settings::getInstance().setOpponentType((tab->getSelected() == "Player") ?
                                                    OpponentType::player : OpponentType::bot); });
     gui->add(opponentTypeTab);
}

void PrePlayScene::createBoardSizeTab(const sf::Vector2u& _windowSize)
{
    boardSizeTab = ResourceManager::getInstance().getGuiTheme()->load("Tab");
    boardSizeTab->insert(6, " 6 ", false);
    boardSizeTab->insert(8, " 8 ", false);
    boardSizeTab->insert(10, " 10 ", false);
    if(Settings::getInstance().getBoardSize() == 6)
        boardSizeTab->select(6);
    else if(Settings::getInstance().getBoardSize() == 8)
        boardSizeTab->select((unsigned int)8);
    else
        boardSizeTab->select(10);
    boardSizeTab->setPosition((_windowSize.x / 2), (_windowSize.y / 2) + 40);  
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
    
    if(Settings::getInstance().getDifficultyLevel() == DifficultyLevel::Easy)
        botLvlTab->select(0);
    else if(Settings::getInstance().getDifficultyLevel() == DifficultyLevel::Medium)
        botLvlTab->select(1);
    else
        botLvlTab->select(2);
        
    botLvlTab->setPosition((_windowSize.x / 2), (_windowSize.y / 2) + 120);
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
    gui->draw();
}
