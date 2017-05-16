#include "PrePlayScene.hpp"

PrePlayScene::PrePlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));


    tgui::Theme::Ptr theme = tgui::Theme::create("../GUITheme/Black.txt");
    //--------------------StartButton--------------------
    startBtn = theme->load("Button");
    startBtn->setSize(150, 50);
    startBtn->setPosition((_windowSize.x / 2) - startBtn->getSize().x / 2,
                          (_windowSize.y / 2) - 120);
    startBtn->setText("Start");
    startBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    
    //--------------------BackButton--------------------
    backBtn = theme->load("Button");
    backBtn->setSize(150, 50);
    backBtn->setText("Back");
    backBtn->setPosition((_windowSize.x / 2) - backBtn->getSize().x / 2,
                         (_windowSize.y / 2) - 40);
    backBtn->connect("mousereleased", [_smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });

    //--------------------BoardSizeTab--------------------
    boardSizeTab = theme->load("Tab");
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
    
    //--------------------OpponentTypeTab--------------------
    opponentTypeTab = theme->load("Tab");
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

    //--------------------BotLevelTab--------------------
    botLvlTab = theme->load("Tab");
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

    gui->add(startBtn);
    gui->add(backBtn);
    gui->add(boardSizeTab);
    gui->add(opponentTypeTab);
    gui->add(botLvlTab);
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
