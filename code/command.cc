#include "command.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "game.h"


Command::Command(Player* player1, Player* player2, Game* game, std::istream *in): player1{player1}, player2{player2}, in{in}, game{game} {
    multiplier = 1;
    curCommand = "";
    curPlayer = player1;
    commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", 
                                        "I", "J", "L", "T", "S", "O", "Z", "restart"};

    special = {"blind", "heavy", "force"};

}

Command::~Command(){}

void Command::readCommand(bool sp){

    std::vector<std::string>*c;
    if (sp == false) {
        c = &commands;
        readNum();
    } else {
        c = &special;
        multiplier = 1;
    }

    *in >> curCommand;

    int len = curCommand.length();

    std::string aCommand = "";

    for (std::string &it : *c) {

        std::string tmp = it.substr(0, len);

        if (tmp == curCommand) {
            if (aCommand == "") {
                aCommand = it;
            } else {
                throw std::logic_error{"There are multiple matching commands for your input, please try again."};
                return;
            }
        }
    }

    curCommand = aCommand;

}

void Command::runCommand(){

    if (curCommand == "left") {
        curPlayer->left(multiplier);
        multiplier = 1;
    } else if (curCommand == "right") {
        curPlayer->right(multiplier);
        multiplier = 1;
    } else if (curCommand == "down") {
        curPlayer->down(multiplier);
        multiplier = 1;
    } else if (curCommand == "clockwise") {
        curPlayer->rotate("cw", multiplier);
        multiplier = 1;
    } else if (curCommand == "counterclockwise") {
        curPlayer->rotate("ccw", multiplier);
        multiplier = 1;
    } else if (curCommand == "drop") {
        curPlayer->drop();
        multiplier = 1;
    } else if (curCommand == "levelup") {
        curPlayer->levelup(multiplier);
        multiplier = 1;
    } else if (curCommand == "leveldown") {
        curPlayer->leveldown(multiplier);
        multiplier = 1;
    } else if (curCommand == "norandom") {
        std::string file;
        *in >> file;
        curPlayer->changeLevelFile(file);
        curPlayer->setRandom();
        
    } else if (curCommand == "random") {
        curPlayer->unsetRandom();
        
    } else if (curCommand == "sequence") {
        
        std::string file;
        *in >> file;
        std::ifstream input {file};
        std::string cmd;

        while (input >> cmd) {
            curCommand = cmd;
            runCommand();
        }
        
    } else if (curCommand == "I" || curCommand == "J" || curCommand == "L" || curCommand == "S" ||  curCommand =="Z" ||  curCommand == "O" || curCommand == "T") {
        char tmp = curCommand.at(0);
        curPlayer->replaceCur(tmp);
        
    } else if (curCommand == "restart") {
        throw (std::string {"Restart Game"});
    }

}

void Command::switchPlayer(Player* player){
    curPlayer = player;
}

void Command::readNum(){

    int input = 1;
    if (*in >> input) {
        if (input > 1) {
            multiplier = input;
        }
        multiplier = input;
    } else {
        in->clear();
    }
}

void Command::specialAction() {
    std::cout << "Congratulations, you have triggered a SPECIAL MOVE!" << std::endl;
    std::cout << "enter one of the following commands: " << std::endl;
    std::cout << "blind: color out the other player's board for one turn" << std::endl;
    std::cout << "L,J,I,...: replace the other player's next object with a block of your choice" << std::endl;
    std::cout << "heavy: make the other player's blocks heavier" << std::endl;
    runSpecial();
}

void Command::runSpecial() {
    readCommand(true);

    if (curCommand == "I" || curCommand == "J" || curCommand == "L" || curCommand == "S" ||  curCommand =="Z" ||  curCommand == "O" || curCommand == "T") {
        if (curPlayer == player1) {
            player2->setForced(curCommand.at(0));
        } else {
            player1->setForced(curCommand.at(0));
        }
    } else if (curCommand == "heavy") {
        if (curPlayer == player1) {
            player2->setHeavy(2);
        } else {
            player1->setHeavy(2);
        }
    } else if (curCommand == "blind") {
        if (curPlayer == player1) {
            player2->setBlind();
        } else {
            player1->setBlind();
        }
    }
}



