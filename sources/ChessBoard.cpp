#include "ChessBoard.hpp"
#include <iostream>

ChessBoard::ChessBoard()
{
	board_width = 8;
	
	board = vector<vector<shared_ptr<sf::RectangleShape>>>(board_width);

	for(auto &line : board)
		for(size_t i = 0; i < board_width; ++i)
			line.push_back(make_shared<sf::RectangleShape>(sf::Vector2f()));
}

ChessBoard::ChessBoard(const int _board_width)
{
	board_width = _board_width;

	board = vector<vector<shared_ptr<sf::RectangleShape>>>(board_width);
	
	for(auto &line : board)
		for(size_t i = 0; i < board_width; ++i)
			line.push_back(make_shared<sf::RectangleShape>(sf::Vector2f()));
}

void ChessBoard::createBoard(const sf::Vector2u& window_size)
{   		
	sf::Vector2u center(window_size.x / 2, window_size.y / 2);

	int cell_edge = window_size.y * 8/9 / board_width;
	int board_edge = cell_edge * board_width;

	sf::Vector2f first_cell_pos(center.x - (board_edge / 2),
				    center.y - (board_edge / 2));
		       			
	int i = 0, j = 0;
	for(auto &line : board) {
		for(auto &cell : line) {
			cell->setSize(sf::Vector2f(cell_edge, cell_edge));

			if((i + j) % 2 == 0)
				cell->setFillColor(sf::Color::White);
			else
				cell->setFillColor(sf::Color::Black);
			
			cell->setPosition(first_cell_pos.x + (cell_edge * i++),
					  first_cell_pos.y + (cell_edge * j));
		}
		i = 0; j++;
	}	
}

void ChessBoard::draw(sf::RenderWindow* window)
{
	for(auto line : board)
		for(auto cell : line)
			window->draw(*cell);
}
