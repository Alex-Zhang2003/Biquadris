#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level {

    int level;

public:

    Level(int level);
    virtual ~Level();
    // throws invalid arguments ?
    virtual char generate() = 0;
    int getLevel() const;
    virtual void changeFile(std::string newFile);

};

#endif

