#ifndef PLAYSCENEMANAGER_HPP
#define PLAYSCENEMANAGER_HPP

#include "PlayScene.hpp"

class PlaySceneManager
{
private:
    PlayScene* pscene;
    sf::RenderWindow* renderWindow;

public:
    PlaySceneManager(sf::RenderWindow* _renderWindow);
    ~PlaySceneManager();
    bool moveQueen(sf::Vector2i _newPosition);
    void hightlightPossibleMoves();
    void drawScene();
};

#endif //PLAYSCENEMANAGER_HPP
