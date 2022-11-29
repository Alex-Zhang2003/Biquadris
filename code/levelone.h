#ifndef LEVELONE_H
#define LEVELONE_H
#include "level.h"

class LevelOne : public Level {

    int seed;
    const double SZProb;
    const double otherProb;

public:

    LevelOne(int level, int seed);
    char generate();


};

#endif



