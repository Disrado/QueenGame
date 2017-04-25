#include "PlayScene.hpp"

PlayScene::PlayScene(sf::Vector2u& _windowSize)
{        
    board = new Board(8);
    board->createBoard(_windowSize);
    
    queen = new Queen(TextureLoader::Instance().getItem("queen"));
    queen->setSpawnPoint(board->getCells()[7][0]);

    background = new sf::Sprite(*(TextureLoader::Instance().getItem("forest_background")));
}

PlayScene::~PlayScene()
{
    delete board;
    delete queen;
	
    if(background)
        delete background;
}

void PlayScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    board->draw(_renderWindow);
    queen->draw(_renderWindow);
}

Queen* PlayScene::getQueen()
{
    return queen;
}

Board* PlayScene::getBoard()
{
    return board;
}

vector<vector<Cell*>> PlayScene::getCells()
{
    return board->getCells();
}
