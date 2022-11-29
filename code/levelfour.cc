#include "levelfour.h"
#include <cstdlib>
#include <fstream>
#include <climits>

LevelFour::LevelFour(int level, int seed, bool random, std::string file): Level{level}, seed{seed}, random{random}, file{file}, prob{1/9} {
    word = 0;
    std::srand(seed);
}

char LevelFour::generate() {
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
}

void LevelFour::setRandom() {
    random = true;
}
void LevelFour::noRandom() {
    random = false;
}

void LevelFour::changeFile(std::string newFile) {
    file = newFile;
}

