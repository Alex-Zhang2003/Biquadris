#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"
#include <string>


class Object {
    Cell* cooordinate1;
    Cell* cooordinate2;
    Cell* cooordinate3;
    Cell* cooordinate4;
public:
    bool left();
    bool right();
    bool down();
    bool drop();
    bool placed();
    virtual bool rotate(std::string dirction, int num) = 0;
};



#endif



