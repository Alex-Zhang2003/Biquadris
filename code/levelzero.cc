#include "levelzero.h"
#include <fstream>
#include <exception>

LevelZero::LevelZero(int level, std::string file): Level{level}, word{0}, file{file} {}

char LevelZero::generate() {
    
    std::ifstream input {file};

    std::string next = "";

    for (int i = 0; i <= word; i++) {
        if (!(input >> next)) {
            word  = -1;
            break;
        }
    }
    word++;
    char obj = next.at(0);

    if (obj == 'I' || obj == 'L' || obj == 'J' || obj == 'S' || obj == 'Z' || obj == 'T' || obj == 'O') {
        return obj;
    } else {
        throw (std::invalid_argument{"the character entered for LeveZero is not valid"});
    }

    
}


