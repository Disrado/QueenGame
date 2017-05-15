#ifndef PAUSESCENE_HPP
#define PAUSESCENE_HPP

#include <TGUI/TGUI.hpp>
#include "memory"
#include "../SceneManager.hpp"

class SceneManager;

class PauseScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> resumeBtn;
    std::shared_ptr<tgui::Button> settingsBtn;
    std::shared_ptr<tgui::Button> exitBtn;

public:
    PauseScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PauseScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PAUSESCENE_HPP
