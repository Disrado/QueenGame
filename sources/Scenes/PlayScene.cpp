#include "PlayScene.hpp"

PlayScene::PlayScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* _smgr)
{        
    board = new Board(Settings::getInstance().getBoardSize());
    board->createBoard(_windowSize);
    
    queen = new Queen(TextureLoader::Instance().getItem("queen"));
    queen->setSpawnPoint(board->getQueenSpawnCell());

    background = new sf::Sprite(*(TextureLoader::Instance().getItem("forest_background")));

    hightlightPossibleMoves();
}

PlayScene::~PlayScene()
{
    delete board;
    delete queen;
	
    if(background)
        delete background;
}

bool PlayScene::moveQueen(sf::Vector2i _newPosition)
{
    auto cellArray = board->getCells();
    
    for(auto &line : cellArray)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(queen->canMove(cell)) {
                    queen->move(cell);
                    return true;
                }
    
    return false;
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
    board->draw(_renderWindow);
    queen->draw(_renderWindow);
}
