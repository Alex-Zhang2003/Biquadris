#include "levelthree.h"
#include <cstdlib>
#include <fstream>
#include <climits>

LevelThree::LevelThree(int level, int seed, bool random, std::string file): Level{level}, seed{seed}, prob{1.0/9.0}, random{random}, file{file} {
    std::srand(seed);
    word = 0;
}

char LevelThree::generate() {
    if (random) {
        double r = ((double) std::rand() / (INT_MAX));
        if (r <= 2 * prob) {
            return 'S';
        } else if (r <= 4 * prob) {
            return 'Z';
        } else if (r <= 5 * prob) {
            return 'I';
        } else if (r <= 6 * prob) {
            return 'L';
        } else if (r <= 7 * prob) {
            return 'J';
        } else if (r <= 8 * prob) {
            return 'T';
        } else {
            return 'O';
        }
    } else {
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
}

void LevelThree::setRandom() {
    random = true;
}
void LevelThree::noRandom() {
    random = false;
}

void LevelThree::changeFile(std::string newFile) {
    file = newFile;
}



