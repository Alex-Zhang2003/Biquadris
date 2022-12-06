#ifndef LEVELFOUR_H
#define LEVELFOUR_H
#include "level.h"
#include <string>

class LevelFour : public Level {

    int seed;
    const double prob;
    bool random;
    std::string file;
    int word;

public:

    LevelFour(int level, int seed, bool random, std::string file);
    char generate();
    void setRandom();
    void noRandom();
    void changeFile(std::string newFile);


};


#endif





