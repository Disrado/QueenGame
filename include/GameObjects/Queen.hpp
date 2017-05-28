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
    vector<shared_ptr<Cell>> availableCells;
    
public:
    Queen(Board* board);
    ~Queen();

    const vector<shared_ptr<Cell>>& getAvailableCells(const sf::Vector2f& _queenPosition);
    int getAvailableCellCount(const sf::Vector2f& _queenPosition);
    const sf::Vector2f& getPosition() const;
    int getConqueredPoints();
    
    bool canMove(shared_ptr<Cell> targetCell, const sf::Vector2f& _queenPosition) const;   
    void move(shared_ptr<Cell> _targetCell);
    
    void draw(sf::RenderWindow* window);
};

#endif //QUEEN_HPP
