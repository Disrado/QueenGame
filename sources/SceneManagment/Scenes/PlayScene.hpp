#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <TGUI/TGUI.hpp>
#include <string>
#include "../../PlayersSystem/PlayArbiter.hpp"
#include "../../GameSystem/Settings.hpp"
#include "../../GameObjects/Board.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;
class PlayArbiter;

class PlayScene : public Scene
{
private:
    Board* board;
    PlayArbiter* playArbiter;
    sf::Text* firstPlayerScore;
    sf::Text* secondPlayerScore;
    sf::Text* firstPlayerName;
    sf::Text* secondPlayerName;
    
public:
    PlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PlayScene();
    void setFirstPlayerScore(int _score);
    void setSecondPlayerScore(int _score);
    Board* getBoard();
    PlayArbiter* getPlayArbiter();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PLAY_SCENE_HPP
 
