#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <TGUI/TGUI.hpp>
#include <string>
#include <memory>
#include "../../Logic/PlayersSystem/PlayArbiter.hpp"
#include "../../GameSystem/Settings.hpp"
#include "../../GameObjects/Board.hpp"
#include "../../GameObjects/Queen.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;
class PlayArbiter;

class PlayScene : public Scene
{
private:
    std::shared_ptr<tgui::Button> pauseBtn;
    sf::Text* secondPlayerScore;
    sf::Text* firstPlayerScore;
    sf::Text* secondPlayerName;
    sf::Text* firstPlayerName;
    PlayArbiter* playArbiter;
    Board* board;
    Queen* queen;

    void createPauseBtn(const sf::Vector2u& _windowSize);
    void createSecondPlayerScore(const sf::Vector2u& _windowSize);
    void createFirstPlayerScore(const sf::Vector2u& _windowSize);
    void createSecondPlayerName(const sf::Vector2u& _windowSize);
    void createFirstPlayerName(const sf::Vector2u& _windowSize);

    
public:
    PlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PlayScene();
    
    void hideGui();
    void unhideGui();
    void hightlightCells();
    
    void setFirstPlayerScore(int _score);
    void setSecondPlayerScore(int _score);
    
    Board* getBoard() const;
    Queen* getQueen() const;
    PlayArbiter* getPlayArbiter() const;

    void update() override;
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PLAY_SCENE_HPP
 
