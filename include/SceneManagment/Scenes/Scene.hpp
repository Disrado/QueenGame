#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include "../../GameSystem/ResourceManager.hpp"
#include "../SceneManager.hpp"

class SceneManager;

class Scene
{
protected:
    std::shared_ptr<sf::Sprite> background;
    SceneManager* smgr = nullptr;
    tgui::Gui* gui = nullptr;

public:
    Scene(SceneManager* _smgr, tgui::Gui* _gui) : smgr(_smgr), gui(_gui)
    {}
    virtual ~Scene() { }
    virtual void update() { }
    virtual void draw(sf::RenderWindow* _renderWindow) = 0;
};

#endif //SCENE_HPP
