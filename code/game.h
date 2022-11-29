#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "textdisplay.h"
#include "graphdisplay.h"
#include "command.h"


class Game {

    bool TextOnly;
    
    Player player1;
    Player player2;
    Player* curPlayer;
    bool p1Dead;
    bool p2Dead;
    int hiScore;
    bool gameFinished;
    Command command;
    TextDisplay textDisplay;
    GraphDisplay *graphicDisplay;
    bool textOnly;
    

public: 

    Game(bool textOnly, int level, std::string file1, std::string file2, int seed = 1);
    ~Game();
    void init();
    void restart();
    void switchPlayer();
    void runTurn();
    bool isGameFinished();
    bool playAgain();

private:

    bool playerInput();


};

#endif



