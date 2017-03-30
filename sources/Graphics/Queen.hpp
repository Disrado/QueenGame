#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Cell.hpp"
#include <SFML/Audio.hpp>
#include <thread>

class Queen
{
private:
	sf::Sprite *queenPicture;
	sf::Texture *queenTexture; 
	sf::Vector2f spawnPoint;	
	sf::Vector2f position;
	
public:
	Queen(std::string texturePath);
	~Queen();
	sf::Vector2f getPosition();
	void setSpawnPoint(Cell* spawnCell);
	bool CanMove(Cell* targetCell);
	void Move(sf::Vector2f position);
	void draw(sf::RenderWindow* const window);
};

#endif //QUEEN_HPP
