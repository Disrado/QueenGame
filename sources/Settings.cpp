#include "Settings.hpp"

Settings::Settings()
{
    boardSize = 8;
}

Settings& Settings::getInstance()
{
    static Settings instance;
    return instance;
}

void Settings::setBoardSize(int _boardSize)
{
    boardSize = _boardSize;
}

int Settings::getBoardSize()
{
    return boardSize;
}
