#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "Scene.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

class SceneManager;

class StartScene : public Scene
{
private:
    shared_ptr<tgui::Button> playBtn;
    shared_ptr<tgui::Button> settingsBtn;
    shared_ptr<tgui::Button> exitBtn;
    tgui::Gui* gui;
    
public:
    StartScene(const sf::Vector2u& _windowSize, tgui::Gui *_gui, SceneManager* smgr);
    ~StartScene();
    void draw(sf::RenderWindow* _renderWindow) override;
    
};

#endif //STARTSCENE
