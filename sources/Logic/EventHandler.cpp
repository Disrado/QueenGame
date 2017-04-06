#include <math.h>
#include "EventHandler.hpp"
#include <iostream>


EventHandler::EventHandler(Board* _board, Queen* _queen) :
    board(_board), queen(_queen)
{}

void EventHandler::HandleMouseActions()
{
    auto mousePosition = sf::Mouse::getPosition();
    
    HightlightPossibleMoves(mousePosition);
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        MoveQueen(mousePosition);
}

void EventHandler::MoveQueen(sf::Vector2i _mousePosition)
{
    auto cellsArray = board->getCells();
    
    for(auto &line : cellsArray) {
        for(auto &cell : line) {
            if(cell->checkBelongs(_mousePosition) &&
               queen->CanMove(cell)) {
                queen->Move(cell->getCenterCoord());
				cell->resetWeight();
            }
        }
    }
}

void EventHandler::HightlightPossibleMoves(sf::Vector2i _mousePosition)
{
    auto cellsArray = board->getCells();
    
    for(auto &line : cellsArray)
        for(auto &cell : line)
            if(queen->CanMove(cell))
                cell->showFrame();
            else
                cell->disableFrame();
}
