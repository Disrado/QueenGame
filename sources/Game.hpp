#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include "ChessBoard.hpp"
#include "MoveHandler.hpp"

using namespace std;

const std::string TEXTURE_PATH = "../media/pictures/Queen.png";

class Game
{
private:
	sf::RenderWindow *app_window;
	ChessBoard *chessBoard;
	Queen *queen;
	MoveHandler *moveHandler;
	
public:
	Game();
	~Game();
	void startLoop();
};



#endif //GAME_HPP
