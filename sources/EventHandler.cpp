#include <math.h>
#include "EventHandler.hpp"
#include <iostream>


EventHandler::EventHandler(Board* _board, Queen* _queen) :
	board(_board), queen(_queen)
{}

void EventHandler::HandleMouseActions()
{
	auto mousePosition = sf::Mouse::getPosition();

	HightlightPossibleMoves(mousePosition);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
		MoveQueen(mousePosition);
}

void EventHandler::MoveQueen(sf::Vector2i _mousePosition)
{
	auto cellsArray = board->getCells();
	
	for(auto &line : cellsArray) {
		for(auto &cell : line) {
			if(cell->checkBelongs(_mousePosition) &&
			   queen->CanMove(cell)) {
				queen->Move(cell->getCenterCoord());
				cell->resetWeight();
			}
		}
	}
}

void EventHandler::HightlightPossibleMoves(sf::Vector2i _mousePosition)
{	
/*	auto cellsArray = board->getCells();

        static auto white_with_frame = new sf::Texture();
        white_with_frame->loadFromFile(("../media/pictures/White_with_frame.png"));

	static auto black_with_frame = new sf::Texture();
        black_with_frame->loadFromFile(("../media/pictures/Black_with_frame.png"));
	
	for(auto &line : cellsArray) {
		for(auto &cell : line) {
			if(queen->CanMove(cell)) {
				if(cell->getType() == CellType::Black)
					cell->setTexture(black_with_frame);
				else
					cell->setTexture(white_with_frame);
			}
		}
	}
	//(x - x1)/(x2 - x1) == (y - y1)/(y2 - y1) - уравнение прямой	
	*/
}

