#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

using namespace std;

class ChessBoard
{
private:
	vector<vector<shared_ptr<sf::RectangleShape>>> board;
	int board_width;
	
public:
	ChessBoard();
	ChessBoard(const int);
	void createBoard(const sf::Vector2u&);
	void draw(sf::RenderWindow*);
};




#endif //CHESS_BOARD_HPP
