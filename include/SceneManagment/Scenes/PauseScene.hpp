#ifndef PAUSESCENE_HPP
#define PAUSESCENE_HPP

#include <TGUI/TGUI.hpp>
#include <memory>
#include "../SceneManager.hpp"
#include "../../GameSystem/ResourceManager.hpp"

class SceneManager;

class PauseScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> resumeBtn;
    std::shared_ptr<tgui::Button> exitBtn;

    void createResumeBtn(const sf::Vector2u& _windowSize);
    void createExitBtn(const sf::Vector2u&  _windowSize);

public:
    PauseScene(const sf::RenderWindow* _renderWindow, tgui::Gui* _gui, SceneManager* _smgr);
    ~PauseScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PAUSESCENE_HPP
