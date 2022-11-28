#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level {

    int level;
    char cur;

public:

    Level(int level);
    ~Level();
    // throws invalid arguments ?
    virtual char generate() = 0;
    int getLevel() const;
    char getCur() const;

};

#endif

