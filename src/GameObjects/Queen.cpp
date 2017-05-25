#include "../../include/GameObjects/Queen.hpp"

Queen::Queen(Board* _board)
{
    board = _board;
    queenPicture = new sf::Sprite(*(ResourceManager::getInstance().getTexture("queen")));
    queenPicture->setOrigin(sf::Vector2f(queenPicture->getLocalBounds().width / 2,
                                         queenPicture->getLocalBounds().height / 2));
    
    shared_ptr<Cell> _spawnCell = board->getCells().back()[0];
    queenPicture->setScale(_spawnCell->getSize().x / 65, _spawnCell->getSize().y / 65);
    _spawnCell->resetWeight();
    
    spawnPoint = sf::Vector2f(_spawnCell->getCenterCoord());
    queenPicture->setPosition(spawnPoint);
    position = sf::Vector2f(spawnPoint);

    availableCells = vector<shared_ptr<Cell>>((board->getCellsPerLine() - 1) * 3);
    conqueredPoints = 0;
    availableCellCount = 0;
}

Queen::~Queen()
{
    delete queenPicture;
}

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
bool Queen::canMove(const sf::Vector2f& _queenPosition, shared_ptr<Cell> _targetCell) const
{   
    if(!_targetCell)
        return false;

   auto newPosition = _targetCell->getCenterCoord();
    
    if(_queenPosition != newPosition && _targetCell->getWeight() != 0 &&
       (newPosition.x == _queenPosition.x || newPosition.y == _queenPosition.y ||
        abs(newPosition.x - _queenPosition.x) == abs(newPosition.y - _queenPosition.y)))
        return  true;
    else
        return false;
}

void Queen::move(shared_ptr<Cell> _targetCell)
{
    if(this->canMove(position, _targetCell)) {
        position = _targetCell->getCenterCoord();
        queenPicture->setPosition(position);
        conqueredPoints = _targetCell->getWeight();
        _targetCell->resetWeight();
    }
}

const sf::Vector2f& Queen::getPosition() const
{
    return position;
}

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
int Queen::getAvailableCellCount(const sf::Vector2f& _queenPosition)
{
    availableCellCount = 0;

    auto cells = board->getCells();
    
    for(auto line : cells)
        for(auto cell : line)
            if(canMove(_queenPosition, cell))
                availableCellCount++;
    
    return availableCellCount;
}

// _queenPosition need in parameters, because bot can sent to this method virtual queen position
const vector<shared_ptr<Cell>>& Queen::getAvailableCells(const sf::Vector2f& _queenPosition)
{
    availableCells.clear();
    
    auto cells = board->getCells();
    for(auto& line : cells)
        for(auto& cell : line)
            if(this->canMove(_queenPosition, cell))
                availableCells.push_back(cell);

    return availableCells;
}

int Queen::getConqueredPoints()
{
    int points = conqueredPoints;
    conqueredPoints = 0;
    return points;
}

void Queen::draw(sf::RenderWindow* window)
{
    window->draw(*queenPicture);
}
