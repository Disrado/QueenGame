#include "../../include/GameObjects/Queen.hpp"
#include <iostream>

Queen::Queen(const sf::Vector2f& _cellSize, Cell* _spawnCell)
{
    spawnPoint = sf::Vector2f(0, 0);
    
    queenPicture = new sf::Sprite(*(ResourceManager::getInstance().getTexture("queen")));
    
    queenPicture->setOrigin(sf::Vector2f(queenPicture->getLocalBounds().width / 2,
                                         queenPicture->getLocalBounds().height / 2));

    queenPicture->setScale(_spawnCell->getSize().x / 65, _spawnCell->getSize().y / 65);
    position = _spawnCell->getCenterCoord();
    queenPicture->setPosition(position);
    _spawnCell->resetWeight();


    inMove = false;
    conqueredPoints = 0;
}

Queen::~Queen()
{
    delete queenPicture;
}

bool Queen::canMove(const sf::Vector2f& _queenPosition, Cell* _targetCell)
{
    auto newPosition = _targetCell->getCenterCoord();
    
    if(_queenPosition != newPosition && _targetCell->getWeight() != 0 && !inMove &&
       (newPosition.x == _queenPosition.x || newPosition.y == _queenPosition.y ||
        abs(newPosition.x - _queenPosition.x) == abs(newPosition.y - _queenPosition.y)))
       return  true;
    else
        return false;
}

void Queen::move(Cell* _targetCell)
{
    if(this->canMove(position, _targetCell)) {
        inMove = true;
        cellToMove = _targetCell;
        //position = _targetCell->getCenterCoord();
        //queenPicture->setPosition(position);
    }
}

const sf::Vector2f& Queen::getPosition()
{
    return position;
}

int Queen::getConqueredPoints()
{
    int points = conqueredPoints;
    conqueredPoints = 0;
    return points;
}

void Queen::update(float _dTime)
{
    float speed = 12.0;
    
    if(inMove) {
        position += {(int)_dTime * speed, (int)-_dTime * speed};
        queenPicture->setPosition(position);
        
        if(cellToMove->checkBelongs(position)) {
            position = cellToMove->getCenterCoord();
            queenPicture->setPosition(position);
            conqueredPoints = cellToMove->getWeight();
            cellToMove->resetWeight();
            inMove = false;
        }
    }        
}

bool Queen::isMove()
{
    return inMove;
}

void Queen::draw(sf::RenderWindow* const window)
{
    window->draw(*queenPicture);
}
