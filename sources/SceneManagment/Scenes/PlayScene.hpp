#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <TGUI/TGUI.hpp>
#include <string>
#include "../../GameSystem/Settings.hpp"
#include "../../GameObjects/Queen.hpp"
#include "../../GameObjects/Board.hpp"
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

class PlayScene : public Scene
{
private:
    Queen *queen;
    Board *board;
    sf::Text* firstPlayerScore;
    sf::Text* secondPlayerScore;
    sf::Text* firstPlayerName;
    sf::Text* secondPlayerName;
    
public:
    PlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PlayScene();
    void setFirstPlayerScore(int _score);
    void setSecondPlayerScore(int _score);
    int moveQueen(sf::Vector2i _newPosition);
    void hightlightPossibleMoves();
    void draw(sf::RenderWindow* _renderWindow) override;
};

#endif //PLAY_SCENE_HPP
 
