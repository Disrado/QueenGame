#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <TGUI/TGUI.hpp>
#include "Scene.hpp"
#include "../Settings.hpp"
#include "../GameObjects/Queen.hpp"
#include "../GameObjects/Board.hpp"
#include "../SceneManagment/SceneManager.hpp"

class SceneManager;

class PlayScene : public Scene
{
private:
    Queen *queen;
    Board *board;
    
public:
    PlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~PlayScene();
    bool moveQueen(sf::Vector2i _newPosition);
    void hightlightPossibleMoves();
    Queen* getQueen();
    Board* getBoard();
    vector<vector<Cell*>> getCells();
    void draw(sf::RenderWindow* _rednerWindow) override;
};

#endif //PLAY_SCENE_HPP
 
