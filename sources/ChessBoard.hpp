#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Cell.hpp"

using namespace std;

class ChessBoard
{
private:
	vector<vector<shared_ptr<Cell>>> board;
	int numCellsPerLine;
	
public:
	ChessBoard();
	ChessBoard(const int);
	void createBoard(const sf::Vector2u&);
	void draw(sf::RenderWindow* const);
};




#endif //CHESS_BOARD_HPP
