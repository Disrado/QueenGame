#include "PlayScene.hpp"

PlayScene::PlayScene(sf::RenderWindow* _app_window)
{
	board = new Board(8);
	board->createBoard(_app_window->getSize());

	queen = new Queen(QUEEN_TEXTURE_PATH);
	queen->setSpawnPoint(board->getCells()[7][0]);

	TextureLoader::Instance().loadAllItemsFromDirectory("/home/nik/Sources/QueenGame/media/pictures/");
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
	background_picture = new sf::Texture(*(TextureLoader::Instance().getItemByName("forest_background")));
	background = new sf::Sprite(*background_picture);
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
