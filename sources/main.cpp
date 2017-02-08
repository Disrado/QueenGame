#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <memory>

#include <fstream>
#include <iostream>

int main()
{
	sf::RenderWindow app_window(sf::VideoMode(1920, 1080), "QueenGame", sf::Style::Fullscreen);

	sf::Texture back_picture;
	back_picture.loadFromFile("../media/pictures/forest-background.png");

	sf::Sprite background(back_picture);

	std::vector<std::vector<std::unique_ptr<sf::RectangleShape>>> board(8);
	
	for(auto &line : board)
		for(size_t i = 0; i < 8; ++i)
			line.push_back(std::make_unique<sf::RectangleShape>(sf::Vector2f(60, 60)));
	
	int number = 0;
	for(auto &line : board) {
		for(auto &cell : line)
			if(number++ % 2 == 0)
				cell->setFillColor(sf::Color::White);
			else
				cell->setFillColor(sf::Color::Black);

		number++;
	}
   		
	sf::Vector2f center(app_window.getSize().x / 2, app_window.getSize().y / 2);

	float board_edge = app_window.getSize().y * 6/9;
	int cell_edge = board_edge / 8;
	board_edge = cell_edge * 8;

	for(auto &line : board)
		for(auto &cell : line)
			cell->setSize(sf::Vector2f((float)cell_edge, (float)cell_edge));
			
	sf::Vector2f cell_position;
	int count = 0;
	for(auto &line : board) {
		for(auto &cell : line) {
			if(count % 8 != 0)
				cell_position.x = cell_position.x + cell_edge;
			else
				if (count == 0) {
					cell_position.x = center.x - (board_edge / 2);
					cell_position.y = center.y - (board_edge / 2);
				} else {
					cell_position.y += cell_edge;
					cell_position.x -= cell_edge * 7;
				}

			cell->setPosition(cell_position);

			count++;
		}
	}
	
	while (app_window.isOpen()) {
		
		sf::Event event;
		while (app_window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				app_window.close();
			
		app_window.clear();

		app_window.draw(background);
		
		for(auto &line : board)
			for(auto &cell : line)
				app_window.draw(*cell);

		app_window.display();
	}
	
	return 0;
}
