#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../../ResourceManagment/ResourceManager.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

class StartScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> playBtn;
    std::shared_ptr<tgui::Button> settingsBtn;
    std::shared_ptr<tgui::Button> exitBtn;
    tgui::Gui* gui;
    
public:
    StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* smgr);
    ~StartScene();
    void draw(sf::RenderWindow* _renderWindow) override;
    
};

#endif //STARTSCENE
