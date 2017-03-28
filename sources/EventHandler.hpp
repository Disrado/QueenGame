#ifndef MOVEHANDLER_HPP
#define MOVEHANDLER_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Queen.hpp"

class EventHandler
{
private:
	Board* board;
	Queen* queen;

private:
	void HightlightPossibleMoves(sf::Vector2i _mousePosition);
	void MoveQueen(sf::Vector2i _mousePosition);
		
public:
	EventHandler(Board* _board, Queen* _queen);
	void HandleMouseActions();
};





#endif //MOVEHANDLER_HPP
