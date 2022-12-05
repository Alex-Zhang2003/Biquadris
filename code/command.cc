#include "command.h"
#include <iostream>
#include <fstream>
#include <exception>
#include "game.h"

#include <iostream>


Command::Command(Player* player1, Player* player2, Game* game, bool test, std::istream *in): player1{player1}, player2{player2}, in{in}, game{game}, numDrop{0} {
    multiplier = 1;
    curCommand = "";
    curPlayer = player1;
    if (test) {
        commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", 
                                        "I", "J", "L", "T", "S", "O", "Z", "restart"};
    } else {
        commands = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown"};
    }
    special = {"blind", "heavy", "force", "I", "J", "L", "T", "S", "O", "Z", "double", "noscore"};



}

Command::~Command(){}

void Command::readCommand(bool sp){

    if (!sp) {
        if (numDrop > 0) {
            return;
        }
    }

    std::vector<std::string>*c;
    if (sp == false) {
        c = &commands;
        readNum();
    } else {
        c = &special;
        multiplier = 1;
    }

    while (true) {

        if (!(*in >> curCommand)) {
            if (in != &std::cin) {
                delete in;
                in = &std::cin;
                if (*in >> curCommand) {
                    throw std::string {"EOF"}; 
                }
            } else {
                throw std::string {"EOF"};
            }
            }
    

        int len = curCommand.length();

        std::string aCommand = "";

        bool valid = false;
        for (std::string &it : *c) {

            std::string tmp = it.substr(0, len);

            if (tmp == curCommand) {
                if (aCommand == "") {
                    aCommand = it;
                    valid = true;
                } else {
                    valid = false;
                }
            }
        }

        curCommand = aCommand;
        if (valid) {
            break;
        }
    }

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
        if (numDrop > 0) {
            numDrop--;
        } else if (multiplier > 1) {
            numDrop = multiplier - 1;
        }
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
        curPlayer->unsetRandom();
        
    } else if (curCommand == "random") {
        curPlayer->setRandom();
        
    } else if (curCommand == "sequence") {
        
        std::string file;
        *in >> file;
        std::ifstream* input = new std::ifstream (file);
        in = input;
        
    } else if (curCommand == "I" || curCommand == "J" || curCommand == "L" || curCommand == "S" ||  curCommand =="Z" ||  curCommand == "O" || curCommand == "T") {
        char tmp = curCommand.at(0);
        curPlayer->replaceCur(tmp);
        
    } else if (curCommand == "restart") {
        throw (std::string {"Game Restarted"});
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
        } else {
            multiplier = 1;
        }
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
    std::cout << "double: doubles the points you gain next time you earn points" << std::endl;
    std::cout << "noscore: the next time your oppnent earns points, their score won't actually go up" << std::endl;
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
    } else if (curCommand == "double") {
        curPlayer->setDouble();
    } else if (curCommand == "noscore") {
        if (curPlayer == player1) {
            player2->setNoScore();
        } else {
            player1->setNoScore();
        }
    }
}



