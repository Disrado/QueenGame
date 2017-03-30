#include "Board.hpp"

Board::Board(const int _numCellsPerLine)
{
	numCellsPerLine = _numCellsPerLine;

	board = vector<vector<Cell*>>(numCellsPerLine,
				      vector<Cell*>(numCellsPerLine));	
	for(auto &line : board)
		for(auto &cell : line)
 			cell = new Cell();
}

Board::~Board()
{
	for(auto &line : board)
		for(auto &cell : line)
			delete cell;
}

void Board::createBoard(const sf::Vector2u& window_size)
{   		
	sf::Vector2u center(window_size.x / 2, window_size.y / 2);

	int board_edge = window_size.y * 8/9;
	int cell_edge = board_edge / numCellsPerLine;

	sf::Vector2f first_cell_pos(center.x - (board_edge / 2),
				    center.y - (board_edge / 2));

	srand(time(NULL));
			
	int row_pos = 0,  column_pos = 0;
	for(auto &line : board) {
		for(auto &cell : line) {
			cell->setSize(sf::Vector2f(cell_edge, cell_edge));

			if((row_pos + column_pos) % 2 == 0) {
				cell->setColor(sf::Color::White);
				cell->setType(CellType::White);
			} else {
				cell->setColor(sf::Color::Black);
				cell->setType(CellType::Black);
			}
			
			cell->setWeight(rand() % 100);	

			cell->setPosition(first_cell_pos.x + (cell_edge * row_pos++),
					  first_cell_pos.y + (cell_edge * column_pos));
		}
		row_pos = 0; column_pos++;
	}	
}

Cell* Board::getCellByID(int _ID)
{
	for(auto line : board)
		for(auto cell : line)
			if(cell->getID() == _ID)
				return cell;

	return nullptr;
}
 
vector<vector<Cell*>> Board::getCells()
{
	return board;
}

void Board::draw(sf::RenderWindow* const window)
{
	for(auto line : board)
		for(auto cell : line)
			cell->draw(window);
}
