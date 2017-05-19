#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>

enum DifficultyLevel { Easy, Medium, Hard };
enum OpponentType { player, bot };
enum Switch { On, Off };

class Settings
{
private:
    int boardSize;
    Switch turnHelpSwitch; 
    OpponentType opponentType;
    DifficultyLevel level;
    std::string firstPlayerName;
    std::string secondPlayerName;

private:
    Settings();
    ~Settings() {}
    
public:
    static Settings& getInstance();

    Settings(Settings const&) = delete;
    Settings& operator= (Settings const&) = delete;

    void enableTurnHelp();
    void disableTurnHelp();
    bool isHelpEnabled();
    
    void setBoardSize(int _boardSize);
    void setOpponentType(OpponentType _type);
    void setDifficultyLevel(DifficultyLevel _level);
    int getBoardSize();
    OpponentType getOpponentType();
    DifficultyLevel getDifficultyLevel();
};

#endif //SETTINGS_HPP
