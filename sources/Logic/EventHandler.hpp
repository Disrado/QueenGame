#ifndef MOVEHANDLER_HPP
#define MOVEHANDLER_HPP

#include "../GameObjects/Board.hpp"
#include "../GameObjects/Queen.hpp"
#include "../ResourceManagment/TextureLoader.hpp"

class EventHandler
{
private:
    Board* board;
    Queen* queen;
    
private:
    void HightlightPossibleMoves(sf::Vector2i _mousePosition);
    void MoveQueen(sf::Vector2i _mousePosition);
    
public:
    EventHandler(Board* _board, Queen* _queen);
    void HandleMouseActions();
};

#endif //MOVEHANDLER_HPP
