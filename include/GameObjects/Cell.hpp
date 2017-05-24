#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "../GameSystem/ResourceManager.hpp"

using namespace std;

const sf::Color TEXT_COLOR = sf::Color(145, 80, 76, 255);

enum CellType { Black, White };

class Cell
{
private:
    sf::RectangleShape* layer;
    sf::Text* weightLabel;
    sf::Vector2f position;
    sf::Vector2f size;
    CellType cellType;
    int weight;
    bool hightLight;

    void setTexture(sf::Texture* _newTexture);
    
public:
    Cell();
    ~Cell();

    bool isHightLight() const;
    bool checkBelongs(const sf::Vector2f& _point) const;
    
    void setWeight(const int);
    void setType(CellType _type);
    void setSize(const sf::Vector2f&);
    void setPosition(const sf::Vector2f& _newPosition);

    CellType getType() const;
    const int getWeight() const;
    const sf::Vector2f& getSize() const;
    const sf::Vector2f getCenterCoord() const;
    
    void showFrame();
    void resetWeight();
    void disableFrame();
    void draw(sf::RenderWindow* const);
};

#endif //CELL_HPP