#ifndef IOBJECT_H
#define IOBJECT_H
#include "object.h"

class iObject : public Object {

    // rotatePos = 0 means horizontal
    // rotatePos = 1 means vertical
    int rotatePos;

public:

    
    iObject(std::vector<std::vector<Cell*>>& board, int level);
    bool insert();
    bool rotate(std::string dirction);
    char getObjType();


};

#endif



