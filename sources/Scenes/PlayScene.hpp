#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include "../GameObjects/Queen.hpp"
#include "../GameObjects/Board.hpp"

class PlayScene
{
private:
    Queen *queen;
    Board *board;
    sf::Sprite *background;
    
public:
    PlayScene(sf::Vector2u& _windowSize);
    ~PlayScene();
    Queen* getQueen();
    Board* getBoard();
    vector<vector<Cell*>> getCells();
    void draw(sf::RenderWindow* _rednerWindow);
};

#endif //PLAY_SCENE_HPP
