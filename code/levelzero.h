#ifndef LEVELZERO_H
#define LEVELZERO_H
#include "level.h"

class LevelZero : public Level {

    int word;
    std::string file;

public:

    LevelZero(int level, std::string file);
    char generate();


};


#endif





