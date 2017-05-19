#ifndef ENDSCENE_HPP
#define ENDSCENE_HPP

#include <string>
#include "../../TGUI/TGUI.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

class EndScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> playAgainBtn;
    std::shared_ptr<tgui::Button> exitBtn;
    sf::Text* winnerNameLbl;
    sf::Text* winnerScoreLbl;

    void createWinnerScoreLbl(const sf::Vector2u& _windowSize,
                              const int _winnerScore);
    void createWinnerNameLbl(const sf::Vector2u& _windowSize,
                             const std::string& _winnerName);
    void createPlayAgainBtn(const sf::Vector2u& _windowSize);
    void createExitBtn(const sf::Vector2u& _windowSize);
    
public:
    EndScene(const sf::Vector2u& _windowSize,
             tgui::Gui* _gui,
             SceneManager* _smgr,
             const std::string& _winnerName,
             const int _winnerScore);
    ~EndScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};


#endif //ENDSCENE_HPP
