#include <string>
#include "cmdl.h"
#include "game.h"
#include <iostream>

CMDL::CMDL(char** str, int num): num{num}, str{str} {}

CMDL::~CMDL() {}

void CMDL::startGame(){
    bool readGraphic = true;
    int seed = 1;
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
        }
        
    }

    Game* play = new Game(readGraphic, level, file1, file2, seed);
    try {
        play->init();
    } catch (std::string exp) {
        if (exp == "EOF") {
            return;
        } else {
            std::cout << exp << std::endl;
            int hiScore = play->getHiScore();
            delete play;
            play = new Game(readGraphic, level, file1, file2, seed);
            play->setHiScore(hiScore);
            play->init();
        }
    }
    
}


