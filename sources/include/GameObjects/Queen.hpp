#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <cmath>
#include "../SFML/Graphics.hpp"
#include "../ResourceManagment/ResourceManager.hpp"
#include "Cell.hpp"

class Queen
{
private:
    sf::Sprite *queenPicture;
    sf::Vector2f spawnPoint;	
    sf::Vector2f position;
    int conqueredPoints;
    
public:
    Queen(const sf::Vector2f& _cellSize, Cell* _spawnCell);
    ~Queen();
    const sf::Vector2f& getPosition();
    int getConqueredPoints();
    bool canMove(const sf::Vector2f& _queenPosition, Cell* targetCell);
    void move(Cell* targetCell);
    void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
