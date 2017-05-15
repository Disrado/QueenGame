#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "../ResourceManagment/ResourceManager.hpp"

using namespace std;

const sf::Color TEXT_COLOR = sf::Color(145, 30, 76, 255);

enum CellType { Black, White };

class Cell
{
private:
    sf::RectangleShape* layer;
    sf::Font* weightLabelFont;
    sf::Text* weightLabel;
    sf::Vector2f position;
    sf::Vector2f size;
    CellType cellType;
    int weight;

private:
    void setTexture(sf::Texture* _newTexture);
    
public:
    Cell();
    ~Cell();

    void setWeight(const int);
    void setType(CellType _type);
    void setSize(const sf::Vector2f&);
    void setPosition(const float, const float);

    CellType getType() const;
    const int getWeight() const;
    const sf::Vector2f getSize() const;
    sf::Vector2f getCenterCoord() const;
    
    void showFrame();
    void resetWeight();
    void disableFrame();
    void draw(sf::RenderWindow* const);
    bool checkBelongs(const sf::Vector2i& _point);
};

#endif //CELL_HPP
