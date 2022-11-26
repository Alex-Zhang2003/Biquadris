#include "command.h"
#include <iostream>
#include <fstream>
#include <exception>


Command::Command(Player* player1, Player* player2): player1{player1}, player2{player2} {
    multiplier = 0;
    curCommand = "";
    curPlayer = player1;
}

Command::~Command(){}

void Command::readCommand(){

    readNum();
    std::cin >> curCommand;

    int len = curCommand.length();
    std::string aCommand = "";

    for (std::string &it : command) {

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

    } else if (curCommand == "right") {

    } else if (curCommand == "down") {
        
    } else if (curCommand == "clockwise") {
        
    } else if (curCommand == "counterclockwise") {
        
    } else if (curCommand == "drop") {
        
    } else if (curCommand == "levelup") {
        
    } else if (curCommand == "norandom") {

        std::string file = "";
        std::cin >> file;
        if (file != "") {

        }
        
    } else if (curCommand == "random") {
        
    } else if (curCommand == "sequence") {
        
        std::string file = "";
        std::cin >> file;
        if (file != "") {
            
        }
        
    } else if (curCommand == "I" || curCommand == "J" || curCommand == "L" || curCommand == "S" ||  curCommand =="Z" ||  curCommand == "O" || curCommand == "T") {
        
    } else if (curCommand == "restart") {
        
    } else {

    }

}

void Command::switchPlayer(){
    if (curPlayer == player1) {
        curPlayer = player2;
    } else {
        curPlayer = player1;
    }
}

void Command::readNum(){

    char test = std::cin.peek();
    int input = 1;
    if (test <= '9' && test >= '0') {
        std::cin >> input;
    }
    multiplier = input;

}





