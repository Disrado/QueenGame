#include "../../include/GameObjects/Board.hpp"

#include <iostream>

Board::Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine)
{ 
    board = cellMatrix_t(_numCellsPerLine, vector<shared_ptr<Cell>>(_numCellsPerLine));

    cellsPerLine = _numCellsPerLine;
    int boardEdge = _windowSize.y * 8/9;
    int cellEdge = boardEdge / _numCellsPerLine;
    
    sf::Vector2f firstCellPos(_windowSize.x / 2 - (boardEdge / 2),
                                _windowSize.y / 2 - (boardEdge / 2));
    
    srand(time(NULL));
    
    int rowIdx = 0,  columnIdx = 0;
    for(auto &line : board) {
        for(auto &cell : line) {
            cell = shared_ptr<Cell>(new Cell());
            
            cell->setSize(sf::Vector2f(cellEdge, cellEdge));
            
            cell->setType(((rowIdx + columnIdx) % 2 == 0) ?
                          CellType::White : CellType::Black);
            
            cell->setWeight(rand() % 99 + 1);	            
            cell->setPosition(firstCellPos.x + (cellEdge * rowIdx++),
                              firstCellPos.y + (cellEdge * columnIdx));
        }
        rowIdx = 0;
        columnIdx++;
    }

    availableCellCount = 0;
}

#include <iostream>

void Board::hightlightPossibleMoves(const vector<shared_ptr<Cell>>& _validCells)
{    
    for(auto &cell : hightlightedCells)
        cell->disableFrame();
    
    hightlightedCells.clear();
    hightlightedCells.insert(hightlightedCells.begin(), _validCells.begin(), _validCells.end());
    
    for(auto &cell : hightlightedCells)
        cell->showFrame();
}

shared_ptr<Cell> Board::getCellByCoord(const sf::Vector2f& _position) const
{
    for(auto &line : board)
        for(auto &cell : line)
            if(cell->checkBelongs(_position))
                return cell;
    
    return nullptr;
}

int Board::getCellsPerLine() const
{
    return cellsPerLine;
    
}
const cellMatrix_t& Board::getCells() const
{
    return board;
}

void Board::draw(sf::RenderWindow* const _renderWindow)
{
    for(auto line : board)
        for(auto cell : line)
            cell->draw(_renderWindow);
}
