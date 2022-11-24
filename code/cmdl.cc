#include <string>
#include "cmdl.h"

CMDL::CMDL(std::string* str, int num): num{num}, str{str} {}

CMDL::~CMDL() {}

void CMDL::startGame(){
    bool text = false;
    bool haveSeed = false;
    int seed = 0;
    std::string file1 = "sequence1.txt";
    std::string file2 = "sequence2.txt";
    int level = 0;

    for (int i = 1; i < num; i++) {
        if (str[i] == "-text"){
            text = true;
        } else if (str[i] == "-seed") {
            haveSeed = true;
            seed = std::stoi(str[i+1]);
            i++;
        } else if (str[i] == "-scriptfile1") {
            file1 = str[i+1]
            i++;
        } else if (str[i] == "-scriptfile2") {
            file2 = str[i+1]
            i++;
        } else if (str[i] == "-startlevel") {
            level = std::stoi(str[i+1]);
            i++;
        }
    }

    if (haveSeed == true) {
        Game* play = new Game(text, level, file1, file2, seed);
        play->init();
    } else {
        Game* play = new Game(text, level, file1, file2);
        play->init();
    }
    
}


