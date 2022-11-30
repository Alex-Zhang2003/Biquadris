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

    readNum();
    *in >> curCommand;

    int len = curCommand.length();

    std::vector<std::string>& c = special;

    if (sp == false) {
        c = commands;
    } 

    std::string aCommand = "";

    for (std::string &it : c) {

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





