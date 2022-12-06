#ifndef LEVELTWO_H
#define LEVELTWO_H
#include "level.h"

class LevelTwo : public Level {

    int seed;
    const double prob;

public:

    LevelTwo(int level, int seed);
    char generate();


};


#endif





