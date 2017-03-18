#include "Game.hpp"

Game::Game()
{
	app_window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
						   "QueenGame",
						   sf::Style::Fullscreen);

	chessBoard = new ChessBoard(8);
	chessBoard->createBoard(app_window->getSize());

	queen = new Queen(TEXTURE_PATH);		
	queen->setSpawnPoint(chessBoard->getCells()[7][0]->getCenterCoord());

	moveHandler = new MoveHandler(chessBoard, queen);
}

Game::~Game()
{
	delete app_window;
	delete chessBoard;
	delete queen;
	delete moveHandler;
}

void Game::startLoop()
{
	sf::Texture back_picture;
	back_picture.loadFromFile("../media/pictures/forest-background.png");
	sf::Sprite background( back_picture );

	while (app_window->isOpen()) {
		
		sf::Event event;
		while (app_window->pollEvent(event))
			if (event.type == sf::Event::Closed)
				app_window->close();
			
		app_window->clear();

		moveHandler->HandleMouseActions();
		
		app_window->draw(background);
		chessBoard->draw(app_window);
		queen->draw(app_window);
			
		app_window->display();
	}
	
}
