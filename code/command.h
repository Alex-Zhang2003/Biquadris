#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <map>
#include "player.h"

class Command {

    std::string curCommand;
    std::vector<std::string> commands;
    int multiplier;
    Player* player1;
    Player* player2;
    Player* curPlayer;

    void readNum();

public:

    Command(Player* player1, Player* player2);
    ~Command();
    
    //throws logic error
    void readCommand();
    void runCommand();
    void switchPlayer();

    std::string getCommand();
    int getMultiplier();
};


#endif
