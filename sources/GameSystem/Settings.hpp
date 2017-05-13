#ifndef SETTINGS_HPP
#define SETTINGS_HPP

enum DifficultyLevel { Easy, Medium, Hard };
enum OpponentType { player, bot };

class Settings
{
private:
    int boardSize;
    OpponentType opponentType;
    DifficultyLevel level;

private:
    Settings();
    ~Settings() {}
    
public:
    static Settings& getInstance();

    Settings(Settings const&) = delete;
    Settings& operator= (Settings const&) = delete;
    
    void setBoardSize(int _boardSize);
    void setOppenentType(OpponentType _type);
    void setDifficultyLevel(DifficultyLevel _level);
    int getBoardSize();
    OpponentType getOpponentType();
    DifficultyLevel getDifficultyLevel();
};

#endif //SETTINGS_HPP
