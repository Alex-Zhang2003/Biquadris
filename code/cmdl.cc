#include <string>
#include "cmdl.h"
#include "game.h"
#include <iostream>
#include <memory>

CMDL::CMDL(char** str, int num): num{num}, str{str} {}

CMDL::~CMDL() {}

// This function starts the game

void CMDL::startGame(){
    bool readGraphic = true;
    int seed = 1;
    bool test = false;
    std::string file1 = "sequence1.txt";
    std::string file2 = "sequence2.txt";
    int level = 0;
    for (int i = 1; i < num; i++) {
        
        std::string tmp {str[i]};
        if (tmp == "-text"){
            readGraphic = false;
        } else if (tmp == "-seed") {
            seed = std::stoi(str[i+1]);
            i++;
        } else if (tmp == "-scriptfile1") {
            file1 = str[i+1];            
            i++;
        } else if (tmp == "-scriptfile2") {
            file2 = str[i+1];
            i++;
        } else if (tmp == "-startlevel") {
            level = std::stoi(str[i+1]);
            i++;
        } else if (tmp == "-enabletest") {
            std::cout << "TEST MODE ENABLED" << std::endl;
            test = true;
        }
        
    }

    auto play = std::make_unique<Game> (readGraphic, level, file1, file2, test, seed);
    std::string result = play->init();
    while (result == "Game Restarted"){
        int hiScore = play->getHiScore();
        play = std::make_unique<Game> (readGraphic, level, file1, file2, test, seed);
        play->setHiScore(hiScore);
        result = play->init();
    }
}





