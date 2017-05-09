#ifndef PLAY_SCENE_HPP
#define PLAY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "../GameObjects/Queen.hpp"
#include "../GameObjects/Board.hpp"

class PlayScene
{
private:
    Queen *queen;
    Board *board;
    sf::Sprite *background;
    
public:
    PlayScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui);
    ~PlayScene();
    bool moveQueen(sf::Vector2i _newPosition);
    void hightlightPossibleMoves();
    Queen* getQueen();
    Board* getBoard();
    vector<vector<Cell*>> getCells();
    void draw(sf::RenderWindow* _rednerWindow);
};

#endif //PLAY_SCENE_HPP
 
