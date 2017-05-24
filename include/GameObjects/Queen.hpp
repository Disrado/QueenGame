#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "../GameSystem/ResourceManager.hpp"
#include "Board.hpp"
#include "Cell.hpp"

class Queen
{
private:
    sf::Sprite *queenPicture;
    sf::Vector2f spawnPoint;	
    sf::Vector2f position;
    int conqueredPoints;
    int availableCellCount;
    Board* board;
    Cell* cellToMove;
    bool isMove;
    
public:
    Queen(Board* board);
    ~Queen();
    sf::Vector2f& getPosition();
    int getConqueredPoints();
    int getAvailableCellCount(const sf::Vector2f& _queenPosition);
    vector<Cell*> getAvailableCells(const sf::Vector2f& _queenPosition);
    bool isMoving() const;
    bool canMove(const sf::Vector2f& _queenPosition, Cell* targetCell);
    void move(Cell* targetCell);
    void update(float _dTime);
    void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
