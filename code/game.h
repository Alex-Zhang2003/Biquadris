#ifndef GAME_H
#define GAME_H

#include <string>

class Game {

    Player player1;
    Player player2;
    Command command;
    TextDisplay textDisplay;
    Graphicdisplay graphicDisplay;
    int startLevel;
    std::string player1File;
    std::string player2File;
    int seed;
    bool readText;
    

public: 

    Game(bool readText, int level, std::string file1, std::string file2, int seed = 0);
    ~Game();
    void init();
    void restart();

};

#endif



