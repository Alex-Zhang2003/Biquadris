#include "levelfour.h"
#include <cstdlib>

LevelFour::LevelFour(int level, int seed, bool random, std::string file): Level{level}, seed{seed}, random{random}, file{file}, prob{1/9} {
    std::srand(seed);
}

char LevelFour::generate() {
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
}

void LevelFour::setRandom() {
    random == true;
}
void LevelFour::noRandom() {
    random == false;
}

void LevelFour::changeFile(std::string newFile) {
    file = newFile;
}

