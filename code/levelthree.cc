#include "levelthree.h"
#include <cstdlib>

LevelThree::LevelThree(int level, int seed, bool random, std::string file): Level{level}, seed{seed}, random{random}, file{file}, prob{1/9} {
    std::srand(seed);
}

char LevelThree::generate() {
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

void LevelThree::setRandom() {
    random == true;
}
void LevelThree::noRandom() {
    random == false;
}

