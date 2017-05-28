#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <fstream>
#include <string>

const std::string PATH_TO_SETTINGS_FILE = "../../settings/SETTINGS.DAT";

enum DifficultyLevel { Easy, Medium, Hard };
enum OpponentType { player, bot };
enum Switch { On, Off };

class Settings
{
private:
    std::string secondPlayerName;
    std::string firstPlayerName;
    OpponentType opponentType;
    DifficultyLevel level;
    Switch turnHelpSwitch;
    float musicVolume;
    Switch music;
    int boardSize;

    Settings();
    ~Settings() {  }

    void readSettingsFromFile();
    
public:
    void writeSettingsToFile() const;

    static Settings& getInstance();

    Settings& operator= (Settings const&) = delete;
    Settings(Settings const&) = delete;
    
    bool isMusicEnabled() const;
    bool isHelpEnabled() const;
    
    void disableTurnHelp();
    void enableTurnHelp();
    void disableMusic();
    void enableMusic();

    void setDifficultyLevel(DifficultyLevel _level);
    void setOpponentType(OpponentType _type);
    void setMusicVolume(float _volume);
    void setBoardSize(int _boardSize);
    
    DifficultyLevel getDifficultyLevel() const;
    float getMusicVolume() const;
    OpponentType getOpponentType() const;
    int getBoardSize() const;
};

#endif //SETTINGS_HPP
