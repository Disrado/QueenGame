#ifndef SETTINGS_HPP
#define SETTINGS_HPP

class Settings
{
private:
    int boardSize;

private:
    Settings();
    
public:
    static Settings& getInstance();

    Settings(Settings const&) = delete;
    Settings& operator= (Settings const&) = delete;
    
    void setBoardSize(int _boardSize);
    int getBoardSize();
};

#endif //SETTINGS_HPP
