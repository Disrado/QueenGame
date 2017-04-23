#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include "Cell.hpp"
#include <math.h>

class Queen
{
private:
    sf::Sprite *queenPicture;
    sf::Vector2f spawnPoint;	
    sf::Vector2f position;
    
public:
    Queen(sf::Texture* _queenTexture);
    ~Queen();
    sf::Vector2f getPosition();
    void setSpawnPoint(Cell* spawnCell);
    bool canMove(Cell* targetCell);
    void move(Cell* targetCell);
    void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
