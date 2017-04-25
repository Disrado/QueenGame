#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <SFML/Graphics.hpp>
#include "../ResourceManagment/TextureLoader.hpp"

class StartScene
{
private:
    sf::Sprite* background;
    
public:
    StartScene();
    void draw(sf::RenderWindow* _renderWindow);
    
};

#endif //STARTSCENE
