#ifndef SINGLEOBJECT_H
#define SINGLEOBJECT_H
#include "object.h"

class SingleObject : public Object {

    int rotatePos;

public:

    
    SingleObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
    ~SingleObject();
    bool insert();
    bool rotate(std::string dirction);
    char getObjType();


};

#endif





