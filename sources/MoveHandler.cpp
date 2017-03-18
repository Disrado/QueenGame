#include "MoveHandler.hpp"

MoveHandler::MoveHandler(ChessBoard* _board, Queen* _queen) :
	board(_board), queen(_queen)
{}

void MoveHandler::HandleMouseActions()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		auto mousePosition = sf::Mouse::getPosition();

		auto cellsArray = board->getCells();

		int cell_ID;
		for(auto line : cellsArray)
			for(auto cell : line)
				if(cell->checkBelongs(mousePosition)) {
					auto center = cell->getCenterCoord();
					queen->Move(center);

				}
	}
}


