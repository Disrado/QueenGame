#ifndef SETTINGSSCENE_HPP
#define SETTINGSSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../../GameSystem/Settings.hpp"
#include "../SceneManager.hpp"

class SceneManager; 

class SettingsScene : public Scene
{
private:
    tgui::Gui* gui;
    std::shared_ptr<tgui::Tab> boardSizeTab;
    std::shared_ptr<tgui::Button> backBtn;
    
public:
    SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~SettingsScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //SETTINGSSCENE_HPP
