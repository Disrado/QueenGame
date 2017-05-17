#ifndef ENDSCENE_HPP
#define ENDSCENE_HPP

#include <TGUI/TGUI.hpp>
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

class EndScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> playAgainBtn;
    std::shared_ptr<tgui::Button> exitBtn;

    void createPlayAgainBtn(const sf::Vector2u& _windowSize);
    void createExitBtn(const sf::Vector2u& _windowSize);
    
public:
    EndScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~EndScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};


#endif //ENDSCENE_HPP
