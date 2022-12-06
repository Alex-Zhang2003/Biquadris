#ifndef ZOBJECT_H
#define ZOBJECT_H
#include "object.h"

class zObject : public Object{
    
    int rotatePos;

public:

    
    zObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
    bool insert();
    bool rotate(std::string direction);
    char getObjType();

};


#endif





