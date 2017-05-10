#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

class Scene
{
protected:
    sf::Sprite* background;

public:
    virtual ~Scene() {}
    virtual void draw(sf::RenderWindow* _window) = 0;
};

#endif //SCENE_HPP
