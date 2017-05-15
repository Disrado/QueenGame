#ifndef SETTINGSSCENE_HPP
#define SETTINGSSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager; 

class SettingsScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> backBtn;
    
public:
    SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~SettingsScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //SETTINGSSCENE_HPP
