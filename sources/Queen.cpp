#include "Queen.hpp"

Queen::Queen(std::string picturePath)
{
	spawnPoint = sf::Vector2f(0, 0);

	queenTexture = new sf::Texture();
	queenTexture->loadFromFile(picturePath);

	queenPicture = new sf::Sprite(*queenTexture);
	queenPicture->setScale(1.3, 1.3);
}

Queen::~Queen()
{
	delete queenTexture;
	delete queenPicture;
}

void Queen::Move(sf::Vector2f &_position)
{
	queenPicture->setPosition(_position);
}

void Queen::setSpawnPoint(sf::Vector2f _position)
{
	auto queenTextureRect = queenPicture->getLocalBounds();

	auto queenTextureCenter = sf::Vector2f(queenTextureRect.width,
					       queenTextureRect.height);
	queenPicture->setOrigin(sf::Vector2f(queenTextureCenter.x / 2,
					     queenTextureCenter.y / 2));
        	
	queenPicture->setPosition(_position);
}

void Queen::draw(sf::RenderWindow* const window)
{
	window->draw(*queenPicture);
}
