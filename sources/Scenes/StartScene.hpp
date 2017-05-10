#ifndef STARTSCENE_HPP
#define STARTSCENE_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <memory>
#include "Scene.hpp"
#include "../SceneManagment/SceneManager.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

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
    tgui::Button* getPlayButton();
    void draw(sf::RenderWindow* _renderWindow) override;
    
};

#endif //STARTSCENE
