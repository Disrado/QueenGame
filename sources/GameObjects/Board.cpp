#include "Board.hpp"

Board::Board(const sf::Vector2u& _windowSize, const int _numCellsPerLine)
{
    board = vector<vector<Cell*>>(_numCellsPerLine, vector<Cell*>(_numCellsPerLine));	
    for(auto &line : board)
        for(auto &cell : line)
            cell = new Cell();

    int boardEdge = _windowSize.y * 8/9;
    int cellEdge = boardEdge / _numCellsPerLine;
    
    sf::Vector2f firstCellPos(_windowSize.x / 2 - (boardEdge / 2),
                                _windowSize.y / 2 - (boardEdge / 2));
    
    srand(time(NULL));
    
    int rowIdx = 0,  columnIdx = 0;
    for(auto &line : board) {
        for(auto &cell : line) {
            cell->setSize(sf::Vector2f(cellEdge, cellEdge));
            
            cell->setType(((rowIdx + columnIdx) % 2 == 0) ? CellType::White : CellType::Black);
            
            cell->setWeight(rand() % 99 + 1);	            
            cell->setPosition(firstCellPos.x + (cellEdge * rowIdx++),
                              firstCellPos.y + (cellEdge * columnIdx));
        }
        rowIdx = 0;
        columnIdx++;
    }

    queen = new Queen(sf::Vector2f(cellEdge, cellEdge), board.back()[0]);
}

Board::~Board()
{
    for(auto &line : board)
        for(auto &cell : line)
            delete cell;
}

int Board::moveQueen(sf::Vector2i _newPosition)
{  
    for(auto &line : board)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(queen->canMove(cell))
                    queen->move(cell);

    return queen->getConqueredPoints();
}

void Board::hightlightPossibleMoves()
{
    for(auto &line : board)
        for(auto &cell : line)
            if(queen->canMove(cell))
                cell->showFrame();
            else
                cell->disableFrame();
}

void Board::draw(sf::RenderWindow* const _renderWindow)
{
    if(Settings::getInstance().helpIsEnabled())
        this->hightlightPossibleMoves();
        
    for(auto line : board)
        for(auto cell : line)
            cell->draw(_renderWindow);

    queen->draw(_renderWindow);
}
