#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <map>

class Command {

    std::string curCommand;
    int multiplier;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    std::vector<std::string> command;

    void readNum();

public:

    Command(Player* player1, Player* player2);
    ~Command();
    
    //throws logic error
    void readCommand();

    void runCommand();
    void switchPlayer();
};


#endif
