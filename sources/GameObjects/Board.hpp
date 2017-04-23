#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.hpp"
#include "Queen.hpp"

using namespace std;

class Board
{
private:
    vector<vector<Cell*>> board;
    int numCellsPerLine;
    
public:
    Board(const int);
    ~Board();
    void createBoard(const sf::Vector2u& _window_size);
    vector<vector<Cell*>> getCells();
    void draw(sf::RenderWindow* const);
};

#endif //BOARD_HPP
