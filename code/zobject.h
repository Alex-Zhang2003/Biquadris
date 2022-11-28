#ifndef ZOBJECT_H
#define ZOBJECT_H
#include "object.h"

class zObject : public Object{
    
    int rotatePos;

public:

    
    zObject(std::vector<std::vector<Cell*>>& board);
    bool insert();
    bool rotate(std::string direction);


};


#endif



