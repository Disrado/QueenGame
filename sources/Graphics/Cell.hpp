#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>
#include "../ResourceManagment/TextureLoader.hpp"

using namespace std;

const string FONT_PATH = "../media/font/DroidSans.ttf";
const sf::Color TEXT_COLOR = sf::Color(145, 30, 76, 255);

enum CellType {Black, White};

class Cell
{
private:
    sf::RectangleShape* layer;
    sf::Text* weightLabel;
    sf::Font* weightLabelFont;
    sf::Vector2f position;
    sf::Vector2f size;
    CellType cellType;
    int weight;
    int ID;
    
public:
    Cell();
    ~Cell();
    void setSize(const sf::Vector2f&);
    void setWeight(const int);
    void setPosition(const float, const float);
    void setTexture(sf::Texture* _newTexture);
    void setType(CellType _type);
    CellType getType();
    const int getWeight();
    void resetWeight();
    sf::Vector2f getCenterCoord();
    void draw(sf::RenderWindow* const);
    bool checkBelongs(const sf::Vector2i& _point);
    int getID();
};

#endif //CELL_HPP
