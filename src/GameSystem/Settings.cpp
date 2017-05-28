#include "../../include/GameSystem/Settings.hpp"

Settings::Settings()
{
    firstPlayerName = "";
    secondPlayerName = "";
    opponentType = OpponentType::bot;
    level = DifficultyLevel::Hard;
    turnHelpSwitch = Switch::On;
    musicVolume = 100;
    music = Switch::Off;
    boardSize = 4;

    readSettingsFromFile();
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

void Settings::setMusicVolume(float _volume)
{
    if(_volume < 0.f)
        _volume = 0.f;
    else if(_volume > 100.f)
        _volume = 100.f;

    musicVolume = _volume;
}

void Settings::setBoardSize(int _boardSize)
{
    boardSize = _boardSize;
}

DifficultyLevel Settings::getDifficultyLevel() const
{
    return level;
}

float Settings::getMusicVolume() const
{
    return musicVolume;
}

OpponentType Settings::getOpponentType() const
{
    return opponentType;
}

int Settings::getBoardSize() const
{
    return boardSize;
}

void Settings::writeSettingsToFile() const
{
    std::ofstream outFile;
    outFile.open(PATH_TO_SETTINGS_FILE, std::ios::trunc | std::ios::binary);
    if(outFile.good())
        outFile.write((char*)this, sizeof(*this));
    else
        std::cout << "Unable to open file for write settings (SETTINGS.DAT): "
                  << outFile.rdstate() << std::endl;
}

void Settings::readSettingsFromFile()
{
    std::ifstream inFile; 
    inFile.open(PATH_TO_SETTINGS_FILE, std::ios::binary);
    if(inFile.good())
        inFile.read((char*)this, sizeof(*this));
    else
        std::cout << "Unable to open file for read settings (SETTINGS.DAT): "
                  << inFile.rdstate() << std::endl;
}
