#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <string>
#include <memory>

using namespace std;

const string FONT_PATH = "../media/font/DroidSans.ttf";
const sf::Color TEXT_COLOR = sf::Color(145, 30, 76, 255);

class Cell
{
private:
	sf::RectangleShape* layer;
	sf::Text* weightLabel;
	sf::Font* weightLabelFont;
	int weight;
	sf::Vector2f size;
	sf::Vector2f position;
	int ID;
			
public:
	Cell();
	~Cell();
	void setColor(const sf::Color&);
	void setSize(const sf::Vector2f&);
	void setWeight(const int);
	void setPosition(const float, const float);
	void setTexture(sf::Texture* _newTexture);
	sf::Color getColor();
	const int getWeight();
	void resetWeight();
	sf::Vector2f getCenterCoord();
	void draw(sf::RenderWindow* const);
	bool checkBelongs(const sf::Vector2i& _point);
	int getID();
};

#endif //CELL_HPP
