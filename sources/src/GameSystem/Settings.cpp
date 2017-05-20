#include "../../include/GameSystem/Settings.hpp"

Settings::Settings()
{
    firstPlayerName = "";
    secondPlayerName = "";
    opponentType = OpponentType::bot;
    level = DifficultyLevel::Easy;
    turnHelpSwitch = Switch::On;
    boardSize = 4;
    music = Switch::On;
}

Settings& Settings::getInstance()
{
    static Settings instance;
    return instance;
}

bool Settings::isMusicEnabled() const
{
    if(music == Switch::On)
        return true;
    return false;
}

bool Settings::isHelpEnabled() const
{
    if(turnHelpSwitch == Switch::On)
        return true;
    return false;
}

void Settings::disableTurnHelp()
{
    turnHelpSwitch = Switch::Off;
}

void Settings::enableTurnHelp()
{
    turnHelpSwitch = Switch::On;
}

void Settings::disableMusic()
{
    music = Switch::Off;
}

void Settings::enableMusic()
{
    music = Switch::On;
}

void Settings::setDifficultyLevel(DifficultyLevel _level)
{
    level = _level;
}

void Settings::setOpponentType(OpponentType _type)
{
    opponentType = _type;
}

void Settings::setBoardSize(int _boardSize)
{
    boardSize = _boardSize;
}

DifficultyLevel Settings::getDifficultyLevel() const
{
    return level;
}

OpponentType Settings::getOpponentType() const
{
    return opponentType;
}

int Settings::getBoardSize() const
{
    return boardSize;
}
