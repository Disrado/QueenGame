#ifndef SCENE_HPP
#define SCENE_HPP

class Scene
{
protected:
    sf::Sprite* background = nullptr;
    tgui::Gui* gui = nullptr;

public:
    Scene() {}
    virtual ~Scene() { delete background; }
    virtual void draw(sf::RenderWindow* _renderWindow) = 0;
};

#endif //SCENE_HPP
