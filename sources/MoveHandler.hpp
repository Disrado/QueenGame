#ifndef MOVEHANDLER_HPP
#define MOVEHANDLER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "ChessBoard.hpp"
#include "Queen.hpp"

class MoveHandler
{
private:
	ChessBoard* board;
	Queen* queen;
		
public:
	MoveHandler(ChessBoard* _board, Queen* _queen);
	void HandleMouseActions();
};





#endif //MOVEHANDLER_HPP
