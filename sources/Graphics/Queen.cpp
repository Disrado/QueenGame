#include "Queen.hpp"
#include <chrono>

Queen::Queen(std::string picturePath)
{
	spawnPoint = sf::Vector2f(0, 0);

	queenTexture = new sf::Texture();
	queenTexture->loadFromFile(picturePath);

	queenPicture = new sf::Sprite(*queenTexture);
	queenPicture->setScale(1.3, 1.3);

	auto queenTextureRect = queenPicture->getLocalBounds();
	auto queenTextureCenter = sf::Vector2f(queenTextureRect.width,
					       queenTextureRect.height);
	queenPicture->setOrigin(sf::Vector2f(queenTextureCenter.x / 2,
					     queenTextureCenter.y / 2));
}

Queen::~Queen()
{
	delete queenTexture;
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

void Queen::Move(const sf::Vector2f _position)
{
	position = _position;
	queenPicture->setPosition(_position);
}

sf::Vector2f Queen::getPosition()
{
	return queenPicture->getPosition();
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
