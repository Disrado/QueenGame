#include "Game.hpp"

Game::Game()
{
	app_window = make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080),
						   "QueenGame",
						   sf::Style::Fullscreen);

	chessBoard = make_shared<ChessBoard>(8);
	chessBoard->createBoard(app_window->getSize());

	queen = std::make_shared<Queen>(sf::Vector2f(0, 0), TEXTURE_PATH);		
	queen->setSpawnPoint(chessBoard->getBoard()[7][0]->getCenterCoord());
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
		
		app_window->draw(background);
		chessBoard->draw(app_window.get());
		queen->draw(app_window.get());
			
		app_window->display();
	}
	
}
