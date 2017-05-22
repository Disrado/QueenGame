#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../ResourceManagment/ResourceManager.hpp"
#include "Cell.hpp"

class Queen
{
private:
    sf::Sprite *queenPicture;
    sf::Vector2f spawnPoint;	
    sf::Vector2f position;
    int conqueredPoints;
    
    Cell* cellToMove;
    bool inMove;
    
public:
    Queen(const sf::Vector2f& _cellSize, Cell* _spawnCell);
    ~Queen();
    const sf::Vector2f& getPosition();
    int getConqueredPoints();
    bool isMove();
    bool canMove(const sf::Vector2f& _queenPosition, Cell* targetCell);
    void move(Cell* targetCell);
    void update(float _dTime);
    void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
