#include "Queen.hpp"

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

    conqueredPoints = 0;
}

Queen::~Queen()
{
    delete queenPicture;
}

bool Queen::canMove(Cell* _targetCell)
{
    auto newPosition = _targetCell->getCenterCoord();
    
    if((newPosition.x == position.x || newPosition.y == position.y ||
        abs(newPosition.x - position.x) == abs(newPosition.y - position.y)) &&
       _targetCell->getWeight() != 0)
       return  true;
    else
        return false;
}

void Queen::move(Cell* _targetCell)
{
    if(this->canMove(_targetCell)) {
        position = _targetCell->getCenterCoord();
        queenPicture->setPosition(position);
        conqueredPoints = _targetCell->getWeight();
        _targetCell->resetWeight();
    }
}

sf::Vector2f Queen::getPosition()
{
    return position;
}

int Queen::getConqueredPoints()
{
    int points = conqueredPoints;
    conqueredPoints = 0;
    return points;
}

void Queen::draw(sf::RenderWindow* const window)
{
    window->draw(*queenPicture);
}
