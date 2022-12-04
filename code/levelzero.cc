#include "levelzero.h"
#include <fstream>
#include <exception>

LevelZero::LevelZero(int level, std::string file): Level{level}, word{0}, file{file} {}

char LevelZero::generate() {
    
    std::ifstream input {file};

    std::string next = "";

    for (int i = 0; i <= word; i++) {
        if (!(input >> next)) {
            word  = 0;
            std::ifstream tmp {file};
            tmp >> next;
            break;
        }
    }
    word++;
    return next.at(0);
}


