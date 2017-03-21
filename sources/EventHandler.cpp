#include <math.h>
#include "EventHandler.hpp"

EventHandler::EventHandler(ChessBoard* _board, Queen* _queen) :
	board(_board), queen(_queen)
{}

void EventHandler::HandleMouseActions()
{
	auto mousePosition = sf::Mouse::getPosition();

	HightlightPossibleMove(mousePosition);

	if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
		MoveQueen(mousePosition);
}

void EventHandler::MoveQueen(sf::Vector2i _mousePosition)
{
	auto cellsArray = board->getCells();
	
	for(auto &line : cellsArray) {
		for(auto &cell : line) {
			if(cell->checkBelongs(_mousePosition)) {
				if(queen->CanMove(cell)) {
					queen->Move(cell->getCenterCoord());
					cell->resetWeight();
				}
			}
		}
	}
}

void EventHandler::HightlightPossibleMove(sf::Vector2i _mousePosition)
{
	auto cellsArray = board->getCells();

        static auto frame = new sf::Texture();
	frame->loadFromFile(("../media/pictures/Frame.png"));
					
//	for(auto line : cellsArray) {
//		for(auto &cell : line) {
//			if(queen->CanMove(cell)) {
//				cell->setTexture(frame);
//			}
//		}
//	}
	//(x - x1)/(x2 - x1) == (y - y1)/(y2 - y1) - уравнение прямой
}

