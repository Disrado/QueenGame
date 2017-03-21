#include "Cell.hpp"
#include <iostream>

Cell::Cell()
{
	layer = new sf::RectangleShape(sf::Vector2f());
	weightLabel = new sf::Text("", sf::Font());
	weightLabelFont = new sf::Font();
	
	if(weightLabelFont->loadFromFile(FONT_PATH))
		weightLabel->setFont(*weightLabelFont);
	else
		std::cout << "Error. Can't load font" << std::endl;
	
	weight = 0;
	size = sf::Vector2f();
	position = sf::Vector2f();
	ID = rand() % 100;
}

Cell::~Cell()
{
	delete layer;
	delete weightLabel;
	delete weightLabelFont;
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

void Cell::setPosition(const float x, const float y)
{
	position = sf::Vector2f(x, y);
	layer->setPosition(x, y);

	auto textRect = weightLabel->getLocalBounds();

	auto cell_center = sf::Vector2f(x + size.x / 2, y + size.y / 2);
	auto text_center = sf::Vector2f(textRect.width / 2, textRect.height / 2);
	
	weightLabel->setOrigin(text_center.x, text_center.y);
	weightLabel->setScale(1.2, 1.2);
	
	weightLabel->setPosition(cell_center.x, cell_center.y);
}

const int Cell::getWeight()
{
	return weight;
}	

sf::Vector2f Cell::getCenterCoord()
{
	return sf::Vector2f(position.x + size.x / 2,
			    position.y + size.y / 2);
}

void Cell::setTexture(sf::Texture* newTexture)
{
	layer->setTexture(newTexture, false);
}

void Cell::setWeight(const int _weight)
{
	weight = _weight;
	weightLabel->setString(std::to_string(_weight));
}

void Cell::resetWeight()
{
	weight = 0;
	weightLabel->setString("");
}

bool Cell::checkBelongs(const sf::Vector2i& _point)
{
	return layer->getGlobalBounds().contains(_point.x, _point.y);	
}

void Cell::draw(sf::RenderWindow* const window)
{
	window->draw(*layer);	
	window->draw(*weightLabel);
}

int Cell::getID()
{
	return ID;
}
