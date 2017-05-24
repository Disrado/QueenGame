#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Cell.hpp"

using namespace std;

class Board
{
private:
    vector<vector<Cell*>> board;
    vector<Cell*> hightlightedCells;
        
public:
    Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine);
    ~Board();
    Cell* getCellByCoord(const sf::Vector2f& _position) const;
    const vector<vector<Cell*>>& getCells() const;
    void hightlightPossibleMoves(const vector<Cell*>& _validCell);
    void update(float _dTime);
    void draw(sf::RenderWindow* _renderWindow);
};

#endif //BOARD_HPP
