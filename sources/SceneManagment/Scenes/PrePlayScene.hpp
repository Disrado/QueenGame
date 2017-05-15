#ifndef PREPLAYSCENE_HPP
#define PREPLAYSCENE_HPP

#include <TGUI/TGUI.hpp>
#include "../../GameSystem/Settings.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

class PrePlayScene : public Scene
{
private:
    std::shared_ptr<tgui::Tab> boardSizeTab;
    std::shared_ptr<tgui::Tab> opponentTypeTab;
    std::shared_ptr<tgui::Tab> botLvlTab;
    std::shared_ptr<tgui::Button> startBtn;
    std::shared_ptr<tgui::Button> backBtn;
    
public:
    PrePlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PrePlayScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PREPLAYSCENE_HPP
