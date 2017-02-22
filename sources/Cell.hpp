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
	shared_ptr<sf::RectangleShape> layer;
	shared_ptr<sf::Text> weightLabel;
	shared_ptr<sf::Font> weightLabelFont;
	int weight;
	sf::Vector2f size;
	sf::Vector2f position;
		
public:
	Cell();
	void setColor(const sf::Color&);
	void setSize(const sf::Vector2f&);
	void setWeight(const int);
	void setPosition(const float, const float);
	sf::Color getColor();
	void resetWeight();
	sf::Vector2f getCenterCoord();
	void draw(sf::RenderWindow* const);
	bool checkBelongs(const sf::Vector2f&);
};

#endif //CELL_HPP
