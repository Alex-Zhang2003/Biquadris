#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <map>
#include "player.h"
#include <iostream>

class Game;

class Command {

    std::string curCommand;
    std::vector<std::string> commands;
    std::vector<std::string> special;
    int multiplier;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    std::istream *in;
    Game* game;

    void readNum();

public:

    Command(Player* player1, Player* player2, Game* game, std::istream *in = &std::cin);
    ~Command();
    
    //throws logic error
    void readCommand(bool special = false);
    void runCommand();
    void switchPlayer(Player* player);
    void specialAction();
    int getMultiplier();

private:
    void runSpecial();
};


#endif
