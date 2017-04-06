#include "Queen.hpp"
#include <chrono>

Queen::Queen(sf::Texture* _newTexture)
{
    spawnPoint = sf::Vector2f(0, 0);
    
    queenPicture = new sf::Sprite(*_newTexture);
    queenPicture->setScale(1.3, 1.3);
    
    auto queenTextureRect = queenPicture->getLocalBounds();
    auto queenTextureCenter = sf::Vector2f(queenTextureRect.width,
                                           queenTextureRect.height);
    queenPicture->setOrigin(sf::Vector2f(queenTextureCenter.x / 2,
                                         queenTextureCenter.y / 2));
}

Queen::~Queen()
{
    delete queenPicture;
}

bool Queen::CanMove(Cell* _targetCell)
{
    auto newPosition = _targetCell->getCenterCoord();
    
    if((newPosition.x == position.x || newPosition.y == position.y ||
        abs(newPosition.x - position.x) == abs(newPosition.y - position.y)) &&
       _targetCell->getWeight() != 0)
        return true;
    else
        return false;
}

void Queen::Move(Cell* _targetCell)
{
    position = _targetCell->getCenterCoord();
    queenPicture->setPosition(position);
    _targetCell->resetWeight();
}

sf::Vector2f Queen::getPosition()
{
    return position;
}

void Queen::setSpawnPoint(Cell* spawnCell)
{
    position = spawnCell->getCenterCoord();
    queenPicture->setPosition(position);
    spawnCell->resetWeight();
}

void Queen::draw(sf::RenderWindow* const window)
{
    window->draw(*queenPicture);
}
