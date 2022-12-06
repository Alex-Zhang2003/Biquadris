#ifndef LOBJECT_H
#define LOBJECT_H

#include "object.h"

class lObject : public Object {

    // rotatePos = 0 :

    //      L
    //    LLL

    // rotatePos = 1:

    //     LL
    //      L
    //      L

    // rotatePos = 2:

    //     LLL
    //     L

    // rotatePos = 3:
    //     L
    //     L
    //     LL

    int rotatePos;

public:

    
    lObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
    bool insert();
    bool rotate(std::string direction);
    char getObjType();


};

#endif





