#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Cell.hpp"
#include "Queen.hpp"

using namespace std;

const std::string TEXTURE_PATH = "../media/pictures/7.png";

class ChessBoard
{
private:
	vector<vector<shared_ptr<Cell>>> board;
	std::shared_ptr<Queen> queen;
	int numCellsPerLine;
	
	
public:
	ChessBoard();
	ChessBoard(const int);
	void createBoard(const sf::Vector2u&);
	void draw(sf::RenderWindow* const);
};




#endif //CHESS_BOARD_HPP
