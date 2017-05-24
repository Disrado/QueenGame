#include "../../include/GameObjects/Queen.hpp"

Queen::Queen(Board* _board)
{
    board = _board;
    queenPicture = new sf::Sprite(*(ResourceManager::getInstance().getTexture("queen")));
    queenPicture->setOrigin(sf::Vector2f(queenPicture->getLocalBounds().width / 2,
                                         queenPicture->getLocalBounds().height / 2));
    
    Cell* _spawnCell = board->getCells().back()[0];
    queenPicture->setScale(_spawnCell->getSize().x / 65, _spawnCell->getSize().y / 65);
    _spawnCell->resetWeight();
    
    spawnPoint = sf::Vector2f(_spawnCell->getCenterCoord());
    queenPicture->setPosition(spawnPoint);
    position = sf::Vector2f(spawnPoint);

    cellToMove = nullptr;
    isMove = false;
    conqueredPoints = 0;
    availableCellCount = 0;
}

Queen::~Queen()
{
    delete queenPicture;
}

#include <iostream>

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
bool Queen::canMove(const sf::Vector2f& _queenPosition, Cell* _targetCell)
{   
    if(!_targetCell || isMove)
        return false;

    // std::cout << _targetCell->getCenterCoord().x << "\t" << _targetCell->getCenterCoord().y  << std::endl;
    
    auto newPosition = _targetCell->getCenterCoord();
    
    if(_queenPosition != newPosition && _targetCell->getWeight() != 0 &&
       (newPosition.x == _queenPosition.x || newPosition.y == _queenPosition.y ||
        abs(newPosition.x - _queenPosition.x) == abs(newPosition.y - _queenPosition.y)))
        return  true;
    else
        return false;
}

void Queen::move(Cell* _targetCell)
{
    if(this->canMove(position, _targetCell)) {
        isMove = true;
        cellToMove = _targetCell;
        conqueredPoints = _targetCell->getWeight();
        //position = _targetCell->getCenterCoord();
        //queenPicture->setPosition(position);
    }
}

sf::Vector2f& Queen::getPosition()
{
    return position;
}

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
int Queen::getAvailableCellCount(const sf::Vector2f& _queenPosition)
{
    availableCellCount = 0;
    
    auto cells = board->getCells();
    
    for(auto line : cells)
        for(auto cell : line)
            if(canMove(_queenPosition, cell))
                availableCellCount++;
    
    return availableCellCount;
}

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
vector<Cell*> Queen::getAvailableCells(const sf::Vector2f& _queenPosition)
{
    vector<Cell*> availableCells = vector<Cell*>();
    auto cells = board->getCells();
    
    for(auto line : cells)
        for(auto cell : line)
            if(canMove(_queenPosition, cell))
                availableCells.push_back(cell);

    return availableCells;
}

int Queen::getConqueredPoints()
{
    int points = conqueredPoints;
    conqueredPoints = 0;
    return points;
}

#include <iostream>

void Queen::update(float _dTime)
{
    if(isMove) {
        float speed = 1.5;
        auto posToMove = cellToMove->getCenterCoord();
        
        int distance = sqrt((posToMove.x - position.x) * (posToMove.x - position.x) +
                             (posToMove.y - position.y) * (posToMove.y - position.y));        

        float dx = speed * _dTime * (posToMove.x - position.x) / distance;
        float dy = speed * _dTime * (posToMove.y - position.y) / distance;

        queenPicture->move(dx, dy);
        position = queenPicture->getPosition();

        if(distance < 2) {
            position = cellToMove->getCenterCoord();
            queenPicture->setPosition(position);
            cellToMove->resetWeight();
            isMove = false;
        }
    }        
}

bool Queen::isMoving() const
{
    return isMove;
}

void Queen::draw(sf::RenderWindow* const window)
{
    window->draw(*queenPicture);
}
