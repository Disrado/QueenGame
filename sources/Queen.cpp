#include "Queen.hpp"

Queen::Queen(sf::Vector2f _position, std::string picturePath)
{
	spawnPoint = _position;

	queenTexture = std::make_shared<sf::Texture>();
	queenTexture->loadFromFile(picturePath);

	queenPicture = std::make_shared<sf::Sprite>(*queenTexture);
	queenPicture->setScale(1.3, 1.3);
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
