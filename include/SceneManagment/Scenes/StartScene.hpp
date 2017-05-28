#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../SceneManager.hpp"
#include "Scene.hpp"
#include "../../GameSystem/Settings.hpp"

class SceneManager;

class StartScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> playBtn;
    std::shared_ptr<tgui::Button> settingsBtn;
    std::shared_ptr<tgui::Button> aboutBtn;
    std::shared_ptr<tgui::Button> exitBtn;

    void createPlayButton(const sf::Vector2u& _windowSize);
    void createSettingsButtons(const sf::Vector2u& _windowSize);
    void createAboutButton(const sf::Vector2u& _windowSize);
    void createExitButton(const sf::Vector2u& _windowSize);
    
public:
    StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* smgr);
    ~StartScene();
    void draw(sf::RenderWindow* _renderWindow) override;
    
};

#endif //STARTSCENE
