#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include "level.h"
#include <string>

class LevelThree : public Level {

    int seed;
    const double prob;
    bool random;
    std::string file;

public:

    LevelThree(int level, int seed, bool random, std::string file);
    char generate();
    void setRandom();
    void noRandom();


};

#endif



