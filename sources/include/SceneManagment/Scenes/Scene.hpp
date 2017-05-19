#ifndef SCENE_HPP
#define SCENE_HPP

#include "../../ResourceManagment/ResourceManager.hpp"
#include "../SceneManager.hpp"

class SceneManager;

class Scene
{
protected:
    sf::Sprite* background = nullptr;
    SceneManager* smgr = nullptr;
    tgui::Gui* gui = nullptr;

public:
    Scene(SceneManager* _smgr, tgui::Gui* _gui) : smgr(_smgr), gui(_gui)
    {}
    virtual ~Scene() { delete background; }
    virtual void draw(sf::RenderWindow* _renderWindow) = 0;
};

#endif //SCENE_HPP
