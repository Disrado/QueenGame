#include "Cell.hpp"

Cell::Cell()
{
    layer = new sf::RectangleShape(sf::Vector2f());
    weightLabel = new sf::Text("", sf::Font());
    weightLabelFont = new sf::Font();
    
    if(weightLabelFont->loadFromFile(FONT_PATH))
        weightLabel->setFont(*weightLabelFont);
    
    weight = 0;
    size = sf::Vector2f();
    position = sf::Vector2f();
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

void Cell::setType(CellType _type)
{
    cellType = _type;
     
    if(_type == CellType::Black)
        layer->setTexture(TextureLoader::Instance().getItemByName("black"));
    else
        layer->setTexture(TextureLoader::Instance().getItemByName("white"));
    
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
                
void Cell::showFrame()
{
    if(this->cellType == CellType::Black)
        this->setTexture(TextureLoader::Instance().getItemByName("black_with_frame"));
    else
        this->setTexture(TextureLoader::Instance().getItemByName("white_with_frame"));
}

void Cell::disableFrame()
{
    if(this->cellType == CellType::Black)
        this->setTexture(TextureLoader::Instance().getItemByName("black"));
    else
        this->setTexture(TextureLoader::Instance().getItemByName("white"));    
}

const int Cell::getWeight() const
{
    return weight;
}

CellType Cell::getType() const
{
    return cellType;
}	

sf::Vector2f Cell::getCenterCoord() const
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
