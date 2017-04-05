#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include "Queen.hpp"
#include "Board.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

const string PATH_TO_PICTURES = "/home/nik/Sources/QueenGame/media/pictures/";

class PlayScene
{
private:
    Queen *queen;
    Board *board;
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
