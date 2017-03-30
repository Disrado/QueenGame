#include "PlayScene.hpp"

PlayScene::PlayScene(sf::RenderWindow *_app_window)
{
	board = new Board(8);
	board->createBoard(_app_window->getSize());

	queen = new Queen(QUEEN_TEXTURE_PATH);
	queen->setSpawnPoint(board->getCells()[7][0]);

	TManager = TextureManager::getInstance();
	TManager.loadAllFilesFromDirectory("../../media/pictures/");
}

PlayScene::~PlayScene()
{
	delete board;
	delete queen;
	
	if(background)
		delete background;
	if(background_picture)
		delete background_picture;
}

void PlayScene::createBackGround()
{
	background_picture = new sf::Texture();
	background_picture->loadFromFile("../media/pictures/forest-background.png");
	background = new sf::Sprite(*background_picture);
}

void PlayScene::draw(sf::RenderWindow *_app_window)
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
