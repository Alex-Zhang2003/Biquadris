#ifndef TOBJECT_H
#define TOBJECT_H

#include "object.h"

class tObject : public Object {

    // rotatePos = 0 :

    //     T
    //    TTT

    // rotatePos = 1:

    //      T
    //     TT
    //      T

    // rotatePos = 2:

    //     TTT
    //      T

    // rotatePos = 3:
    //     T
    //     TT
    //     T

    int rotatePos;

public:

    
    tObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
    bool insert();
    bool rotate(std::string dirction);
    char getObjType();


};

#endif





