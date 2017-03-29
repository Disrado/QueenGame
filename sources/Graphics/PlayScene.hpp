#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include "Queen.hpp"
#include "Board.hpp"

const std::string QUEEN_TEXTURE_PATH = "../media/pictures/Queen.png";

class PlayScene
{
private:
	Queen *queen;
	Board *board;
	sf::Texture *background_picture;
	sf::Sprite *background;

public:
	PlayScene(sf::RenderWindow *_app_window);
	~PlayScene();
	void createBackGround();
	void createQueen();
	void createBoard();
	void draw(sf::RenderWindow *_app_window);
	Queen* getQueen();
	Board* getBoard();
};

#endif //PLAY_SCENE_HPP
