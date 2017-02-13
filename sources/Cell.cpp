#include "Cell.hpp"
#include <iostream>


Cell::Cell()
{
	layer = make_shared<sf::RectangleShape>(sf::Vector2f());
	weightLabel = make_shared<sf::Text>("", sf::Font());
	weightLabelFont = make_shared<sf::Font>();
	
	if(weightLabelFont->loadFromFile(FONT_PATH))
		weightLabel->setFont(*weightLabelFont);
	else
		std::cout << "Error. Can't load font" << std::endl;

	weight = 0;
	size = sf::Vector2f();
	position = sf::Vector2f();
	center = sf::Vector2f();
}

void Cell::setSize(const sf::Vector2f& _size)
{
	size = _size;
	layer->setSize(_size);
}

void Cell::setColor(const sf::Color& color)
{
	layer->setFillColor(color);
	weightLabel->setColor(TEXT_COLOR);
}

void Cell::setWeight(const int _weight)
{
	weight = _weight;
	weightLabel->setString(std::to_string(_weight));
} 

void Cell::setPosition(const sf::Vector2f& _position)
{
	position = _position;
	layer->setPosition(_position);
	weightLabel->setPosition(_position);
}

void Cell::setPosition(const float x, const float y)
{
	position = sf::Vector2f(x, y);
	layer->setPosition(x, y);
	weightLabel->setPosition(x, y);
}

sf::Color Cell::getColor()
{
	return layer->getFillColor();
}
	
void Cell::draw(sf::RenderWindow* const window)
{
	window->draw(*layer);	
	window->draw(*weightLabel);
}

bool Cell::checkBelongs(const sf::Vector2f&)
{
	//
}
