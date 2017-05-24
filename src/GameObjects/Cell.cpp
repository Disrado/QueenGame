#include "../../include/GameObjects/Cell.hpp"

Cell::Cell()
{
    layer = new sf::RectangleShape(sf::Vector2f());
    weightLabel = new sf::Text("", *(ResourceManager::getInstance().getFont("Kurale")));
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

bool Cell::isHightLight() const
{
    return hightLight;
}

bool Cell::checkBelongs(const sf::Vector2f& _point) const
{
    return layer->getGlobalBounds().contains(_point.x, _point.y);	
}

void Cell::setSize(const sf::Vector2f& _size)
{
    size = _size;
    weightLabel->setCharacterSize(_size.x * 0.6);
    layer->setSize(_size);
}

void Cell::setType(CellType _type)
{
    cellType = _type;
     
    if(_type == CellType::Black)
        layer->setTexture(ResourceManager::getInstance().getTexture("black"));
    else
        layer->setTexture(ResourceManager::getInstance().getTexture("white"));
} 

void Cell::setPosition(const sf::Vector2f& _newPosition)
{
    position = sf::Vector2f(_newPosition);
    layer->setPosition(_newPosition);
    
    auto cell_center = sf::Vector2f(_newPosition.x + size.x / 2, _newPosition.y + size.y / 2);
    auto text_center = sf::Vector2f(weightLabel->getLocalBounds().width / 2,
                                    weightLabel->getLocalBounds().height / 2);
    
    weightLabel->setOrigin(text_center.x, text_center.y);
    weightLabel->setPosition(cell_center.x, cell_center.y - 15);
}
                
void Cell::showFrame()
{
    if(this->cellType == CellType::Black)
        this->setTexture(ResourceManager::getInstance().getTexture("black_with_frame"));
    else
        this->setTexture(ResourceManager::getInstance().getTexture("white_with_frame"));

    hightLight = true;
}

void Cell::disableFrame()
{
    if(this->cellType == CellType::Black)
        this->setTexture(ResourceManager::getInstance().getTexture("black"));
    else
        this->setTexture(ResourceManager::getInstance().getTexture("white"));

    hightLight = false;
}

const int Cell::getWeight() const
{
    return weight;
}

const sf::Vector2f& Cell::getSize() const
{
    return size;
}

CellType Cell::getType() const
{
    return cellType;
}	

const sf::Vector2f Cell::getCenterCoord() const
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

void Cell::draw(sf::RenderWindow* const window)
{
    window->draw(*layer);	
    window->draw(*weightLabel);
}
