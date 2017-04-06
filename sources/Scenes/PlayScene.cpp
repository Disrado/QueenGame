#include "PlayScene.hpp"

PlayScene::PlayScene(sf::RenderWindow* _app_window)
{        
    TextureLoader::Instance().loadAllItemsFromDirectory(PATH_TO_PICTURES);

    board = new Board(8);
    board->createBoard(_app_window->getSize());
    
    queen = new Queen(TextureLoader::Instance().getItemByName("queen"));
    queen->setSpawnPoint(board->getCells()[7][0]);

    background = new sf::Sprite(*(TextureLoader::Instance().getItemByName("forest_background")));
}

PlayScene::~PlayScene()
{
    delete board;
    delete queen;
	
    if(background)
        delete background;
}

void PlayScene::draw(sf::RenderWindow* _app_window)
{
    _app_window->draw(*background);
    board->draw(_app_window);
    queen->draw(_app_window);
}

Queen* PlayScene::getQueen()
{
    return queen;
}

Board* PlayScene::getBoard()
{
    return board;
}
