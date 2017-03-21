#ifndef MOVEHANDLER_HPP
#define MOVEHANDLER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "ChessBoard.hpp"
#include "Queen.hpp"

class EventHandler
{
private:
	ChessBoard* board;
	Queen* queen;

private:
	void HightlightPossibleMove(sf::Vector2i _mousePosition);
	void MoveQueen(sf::Vector2i _mousePosition);
		
public:
	EventHandler(ChessBoard* _board, Queen* _queen);
	void HandleMouseActions();
};





#endif //MOVEHANDLER_HPP
