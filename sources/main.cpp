#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "ChessBoard.hpp"

int main()
{
	sf::RenderWindow app_window(sf::VideoMode(1920, 1080), "QueenGame", sf::Style::Fullscreen);

	sf::Texture back_picture;
	back_picture.loadFromFile("../media/pictures/forest-background.png");

	sf::Sprite background(back_picture);
	
	ChessBoard chessBoard(8);
	chessBoard.createBoard(app_window.getSize());
	
	while (app_window.isOpen()) {
		
		sf::Event event;
		while (app_window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				app_window.close();
			
		app_window.clear();
		
		app_window.draw(background);
		chessBoard.draw(&app_window);

		app_window.display();
	}
	
	return 0;
}
