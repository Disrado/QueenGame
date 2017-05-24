#include "../../include/GameObjects/Board.hpp"

Board::Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine)
{ 
    board = vector<vector<Cell*>>(_numCellsPerLine, vector<Cell*>(_numCellsPerLine));	
    hightlightedCells = vector<Cell*>();
    hightlightedCells.reserve((_numCellsPerLine - 1) * 3);
        
    int boardEdge = _windowSize.y * 8/9;
    int cellEdge = boardEdge / _numCellsPerLine;
    
    sf::Vector2f firstCellPos(_windowSize.x / 2 - (boardEdge / 2),
                                _windowSize.y / 2 - (boardEdge / 2));
    
    srand(time(NULL));
    
    int rowIdx = 0,  columnIdx = 0;
    for(auto &line : board) {
        for(auto &cell : line) {
            cell = new Cell();
            
            cell->setSize(sf::Vector2f(cellEdge, cellEdge));
            
            cell->setType(((rowIdx + columnIdx) % 2 == 0) ?
                          CellType::White : CellType::Black);
            
            cell->setWeight(rand() % 99 + 1);	            
            cell->setPosition({firstCellPos.x + (cellEdge * rowIdx++),
                        firstCellPos.y + (cellEdge * columnIdx)});
        }
        rowIdx = 0;
        columnIdx++;
    }
}

Board::~Board()
{
    for(auto &line : board)
        for(auto &cell : line)
            delete cell;
}

void Board::hightlightPossibleMoves(const vector<Cell*>& _validCell)
{    
    for(auto &cell : hightlightedCells)
        cell->disableFrame();
    
    hightlightedCells.clear();
    hightlightedCells.insert(hightlightedCells.begin(), _validCell.begin(), _validCell.end());
    
    for(auto &cell : hightlightedCells)
        cell->showFrame();
}

Cell* Board::getCellByCoord(const sf::Vector2f& _position) const
{
    for(auto &line : board)
        for(auto &cell : line)
            if(cell->checkBelongs(_position))
                return cell;
    
    return nullptr;
}

const vector<vector<Cell*>>& Board::getCells() const
{
    return board;
}

void Board::update(float _dTime)
{

}

void Board::draw(sf::RenderWindow* const _renderWindow)
{
    for(auto line : board)
        for(auto cell : line)
            cell->draw(_renderWindow);
}
