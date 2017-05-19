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
    int availableCellCount;
    Queen* queen;

private:
    void hightlightPossibleMoves();
    
public:
    Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine);
    ~Board();
    int getQueenPoints() const;
    bool queenCanMove(const sf::Vector2f& _newPosition) const;
    int getAvailableCellCount();
    vector<Cell*> getAvailableCells(const sf::Vector2f& _queenPosition) const;
    const sf::Vector2f& getQueenPosition() const;
    void moveQueen(const sf::Vector2f& _newPosition);
    void draw(sf::RenderWindow* _renderWindow);
};

#endif //BOARD_HPP
