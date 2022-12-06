#ifndef SOBJECT_H
#define SOBJECT_H
#include "object.h"

class sObject : public Object{
    
    int rotatePos;

public:

    
    sObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
    bool insert();
    bool rotate(std::string direction);
    char getObjType();


};

#endif





