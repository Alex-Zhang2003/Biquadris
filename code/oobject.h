#ifndef OOBJECT_H
#define OOBJECT_H
#include "object.h"

class oObject : public Object {

    int rotatePos;

public:

    
    oObject(std::vector<std::vector<Cell*>>& board, int level);
    bool insert();
    bool rotate(std::string dirction);
    char getObjType();

};

#endif





