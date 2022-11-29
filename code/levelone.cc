#include "levelone.h"
#include <cstdlib>
#include <climits>

LevelOne::LevelOne(int level, int seed): Level{level}, seed{seed}, SZProb{1/12}, otherProb{1/6} {
    srand(seed);
}

char LevelOne::generate() {
    double r = ((double) rand() / (INT_MAX));
    if (r <= SZProb) {
        return 'S';
    } else if (r <= 2 * SZProb) {
        return 'Z';
    } else if (r <= 2 * otherProb) {
        return 'I';
    } else if (r <= 3 * otherProb) {
        return 'L';
    } else if (r <= 4 * otherProb) {
        return 'J';
    } else if (r <= 5 * otherProb) {
        return 'T';
    } else {
        return 'O';
    }
}

