#ifndef SETTINGSSCENE_HPP
#define SETTINGSSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../../GameSystem/Settings.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager; 

class SettingsScene : public Scene
{
private:
    std::shared_ptr<tgui::Tab> musicSwitchTab;
    std::shared_ptr<tgui::Tab> helpSwitchTab;
    std::shared_ptr<tgui::Button> backBtn;
    std::shared_ptr<sf::Text> musicLbl;
    std::shared_ptr<sf::Text> helpLbl;
    
    void createMusicSwitchTab(const sf::Vector2u& _windowSize);
    void createHelpSwitchTab(const sf::Vector2u& _windowSize);
    void createBackButton(const sf::Vector2u& _windowSize);
    void createLabels(const sf::Vector2u& _windowSize);
    
public:
    SettingsScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~SettingsScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //SETTINGSSCENE_HPP
