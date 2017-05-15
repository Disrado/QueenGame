#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include "../GameSystem/Settings.hpp"
#include <vector>
#include "Cell.hpp"
#include "Queen.hpp"

using namespace std;

class Board
{
private:
    vector<vector<Cell*>> board;
    Queen* queen;

private:
    void hightlightPossibleMoves();
    
public:
    Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine);
    ~Board();
    int moveQueen(sf::Vector2i _newPosition);
    void draw(sf::RenderWindow* _renderWindow);
};

#endif //BOARD_HPP
