#include "Board.hpp"

Board::Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine)
{ 
    board = vector<vector<Cell*>>(_numCellsPerLine, vector<Cell*>(_numCellsPerLine));	

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
            cell->setPosition(firstCellPos.x + (cellEdge * rowIdx++),
                              firstCellPos.y + (cellEdge * columnIdx));
        }
        rowIdx = 0;
        columnIdx++;
    }

    queen = new Queen(sf::Vector2f(cellEdge, cellEdge), board.back()[0]);

    availableCellCount = 0;
}

Board::~Board()
{
    for(auto &line : board)
        for(auto &cell : line)
            delete cell;
}

int Board::getQueenPoints() const
{
    return queen->getConqueredPoints();
}

bool Board::queenCanMove(const sf::Vector2f& _newPosition) const
{
    for(auto &line : board)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(queen->canMove(queen->getPosition(), cell))
                    return true;
    return false;
}

void Board::moveQueen(const sf::Vector2f& _newPosition)
{
    for(auto &line : board)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(queen->canMove(queen->getPosition(), cell))
                    queen->move(cell);
}

void Board::hightlightPossibleMoves()
{
    for(auto &line : board)
        for(auto &cell : line)
            if(queen->canMove(queen->getPosition(), cell))
                cell->showFrame();
            else
                cell->disableFrame();
}

int Board::getAvailableCellCount()
{
    availableCellCount = 0;
    
    for(auto line : board)
        for(auto cell : line)
            if(queen->canMove(queen->getPosition(), cell))
                availableCellCount++;

    return availableCellCount;
}

vector<Cell*> Board::getAvailableCells(const sf::Vector2f& _queenPosition) const
{
    vector<Cell*> availableCells = vector<Cell*>();
    
    
    for(auto line : board)
        for(auto cell : line)
            if(queen->canMove(_queenPosition, cell))
                availableCells.push_back(cell);

    return availableCells;
}

const sf::Vector2f& Board::getQueenPosition() const
{
    return queen->getPosition();
}

void Board::draw(sf::RenderWindow* const _renderWindow)
{
    if(Settings::getInstance().isHelpEnabled())
        this->hightlightPossibleMoves();
        
    for(auto line : board)
        for(auto cell : line)
            cell->draw(_renderWindow);

    queen->draw(_renderWindow);
}
