#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <SFML/System/Vector2.hpp>
#include <string>

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
    int boardSize;
    Switch music;

private:
    Settings();
    ~Settings() {}
    
public:
    static Settings& getInstance();

    Settings(Settings const&) = delete;
    Settings& operator= (Settings const&) = delete;

    bool isMusicEnabled() const;
    bool isHelpEnabled() const;

    void disableTurnHelp();
    void enableTurnHelp();
    void disableMusic();
    void enableMusic();
    
    void setDifficultyLevel(DifficultyLevel _level);
    void setOpponentType(OpponentType _type);
    void setBoardSize(int _boardSize);

    DifficultyLevel getDifficultyLevel() const;
    OpponentType getOpponentType() const;
    int getBoardSize() const;



};

#endif //SETTINGS_HPP
