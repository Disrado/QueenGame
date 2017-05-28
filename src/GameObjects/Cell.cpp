#include "../../include/GameObjects/Cell.hpp"

Cell::Cell()
{
    layer = new sf::RectangleShape(sf::Vector2f());
    weightLabel = new sf::Text("", *(ResourceManager::getInstance().getFont("Kurale")));
    //    weightLabel->setCharacterSize(60);
    weightLabel->setOutlineThickness(1.0);
    weightLabel->setFillColor(sf::Color(50, 120, 100, 255));
    weightLabel->setOutlineColor(sf::Color(50, 100, 100, 255));
    
    weight = 0;
    size = sf::Vector2f();
    position = sf::Vector2f();
}

Cell::~Cell()
{
    delete layer;
    delete weightLabel;
}

bool Cell::checkBelongs(const sf::Vector2f& _point) const
{
    return layer->getGlobalBounds().contains(_point.x, _point.y);	
}

void Cell::setPosition(const sf::Vector2f& _newPosition)
{
    position = sf::Vector2f(_newPosition.x, _newPosition.y);
    layer->setPosition(_newPosition.x, _newPosition.y);
    
    auto textRect = weightLabel->getLocalBounds();
    
    auto cell_center = sf::Vector2f(_newPosition.x + size.x / 2,
                                    _newPosition.y + size.y / 2);
    auto text_center = sf::Vector2f(textRect.width / 2, textRect.height / 2);
    
    weightLabel->setOrigin(text_center.x, text_center.y);
    
    weightLabel->setPosition(cell_center.x, cell_center.y - 15);
}

void Cell::setSize(const sf::Vector2f& _newSize)
{
    size = _newSize;
    weightLabel->setCharacterSize(size.x * 0.6);
    layer->setSize(size);
}

void Cell::setType(CellType _newType)
{
    cellType = _newType;
     
    if(_newType == CellType::Black)
        layer->setTexture(ResourceManager::getInstance().getTexture("black"));
    else
        layer->setTexture(ResourceManager::getInstance().getTexture("white"));
} 


void Cell::setWeight(const int _newWeight)
{
    weight = _newWeight;
    weightLabel->setString(std::to_string(weight));
}

const sf::Vector2f Cell::getCenterCoord() const
{
    return sf::Vector2f(position.x + size.x / 2,
                        position.y + size.y / 2);
}

const sf::Vector2f& Cell::getSize() const
{
    return size;
}


const int Cell::getWeight() const
{
    return weight;
}

CellType Cell::getType() const
{
    return cellType;
}	

void Cell::showFrame()
{
    if(this->cellType == CellType::Black)
        layer->setTexture(ResourceManager::getInstance().getTexture("black_with_frame"));
    else
        layer->setTexture(ResourceManager::getInstance().getTexture("white_with_frame"));
}

void Cell::disableFrame()
{
    if(this->cellType == CellType::Black)
        layer->setTexture(ResourceManager::getInstance().getTexture("black"));
    else
        layer->setTexture(ResourceManager::getInstance().getTexture("white"));    
}

void Cell::resetWeight()
{
    weight = 0;
    weightLabel->setString("");
}

void Cell::draw(sf::RenderWindow* const window)
{
    window->draw(*layer);	
    window->draw(*weightLabel);
}
