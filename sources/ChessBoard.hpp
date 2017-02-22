#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Cell.hpp"
#include "Queen.hpp"

using namespace std;

class ChessBoard
{
private:
	vector<vector<shared_ptr<Cell>>> board;

	int numCellsPerLine;
		
public:
	ChessBoard(const int);
	void createBoard(const sf::Vector2u&);
	vector<vector<shared_ptr<Cell>>> getBoard();
	void draw(sf::RenderWindow* const);
};




#endif //CHESS_BOARD_HPP
