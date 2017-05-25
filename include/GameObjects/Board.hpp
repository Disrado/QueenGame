#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "../GameSystem/Settings.hpp"
#include "Cell.hpp"

using namespace std;

typedef vector<vector<shared_ptr<Cell>>> cellMatrix_t;

class Board
{
private:
    cellMatrix_t board;
    int availableCellCount;
    int cellsPerLine;
    vector<shared_ptr<Cell>> hightlightedCells;
    
public:
    Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine);
    
    shared_ptr<Cell> getCellByCoord(const sf::Vector2f& _position) const;
    int getCellsPerLine() const;
    const cellMatrix_t& getCells() const;
    void hightlightPossibleMoves(const vector<shared_ptr<Cell>>& _validCells);

    void draw(sf::RenderWindow* _renderWindow);
};

#endif //BOARD_HPP
