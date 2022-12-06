#include "leveltwo.h"
#include <cstdlib>
#include <climits>

LevelTwo::LevelTwo(int level, int seed): Level{level}, seed{seed}, prob{1.0/7.0} {
    std::srand(seed);
}

char LevelTwo::generate() {
    double r = ((double) std::rand() / (INT_MAX));
    if (r <= prob) {
        return 'S';
    } else if (r <= 2 * prob) {
        return 'Z';
    } else if (r <= 3 * prob) {
        return 'I';
    } else if (r <= 4 * prob) {
        return 'L';
    } else if (r <= 5 * prob) {
        return 'J';
    } else if (r <= 6 * prob) {
        return 'T';
    } else {
        return 'O';
    }
}




