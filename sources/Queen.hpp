#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Queen
{
private:
	sf::Sprite *queenPicture;
	sf::Texture *queenTexture; 
	sf::Vector2f spawnPoint;	
	
public:
	Queen(std::string texturePath);
	~Queen();
	void setSpawnPoint(sf::Vector2f);
	void Move(sf::Vector2f& position);
	void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
