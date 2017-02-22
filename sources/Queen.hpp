#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Queen
{
private:
	std::shared_ptr<sf::Sprite> queenPicture;
	std::shared_ptr<sf::Texture> queenTexture; 
	sf::Vector2f spawnPoint;	
	
public:
	Queen(sf::Vector2f _position, std::string);
	void setSpawnPoint(sf::Vector2f);
	void draw(sf::RenderWindow* const window);
};



#endif //QUEEN_HPP
