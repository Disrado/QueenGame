#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include "ChessBoard.hpp"

using namespace std;

const std::string TEXTURE_PATH = "../media/pictures/Queen.png";

class Game
{
private:
	shared_ptr<sf::RenderWindow> app_window;
	shared_ptr<ChessBoard> chessBoard;
	std::shared_ptr<Queen> queen;	

private:
	
	
public:
	Game();
	void startLoop();
};



#endif //GAME_HPP
