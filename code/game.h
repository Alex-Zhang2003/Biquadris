#ifndef GAME_H
#define GAME_H

#include <string>
#include "player.h"
#include "textdisplay.h"
#include "graphdisplay.h"
#include "command.h"


class Game {

    bool readGraphic;
    Player player1;
    Player player2;
    Player* curPlayer;
    int hiScore;
    Command command;
    TextDisplay textDisplay;
    GraphDisplay *graphicDisplay;

public: 

    Game(bool readGraphic, int level, std::string file1, std::string file2, bool test, int seed = 1);
    ~Game();
    std::string init();
    void switchPlayer();
    void runTurn();
    bool isGameFinished();
    bool playAgain();
    int getHiScore();
    void setHiScore(int score);
    bool revivePlayer();

private:

    bool playerInput();


};

#endif



