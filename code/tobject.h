#ifndef TOBJECT_H
#define TOBJECT_H

#include "object.h"
#include "cell.h"

class tObject : public Object {

    // rotatePos = 1 :

    //     T
    //    TTT

    // rotatePos = 2:

    //      T
    //     TT
    //      T

    // rotatePos = 3:

    //     TTT
    //      T

    // rotatePos = 4:
    //     T
    //     TT
    //     T

    int rotatePos;

public:

    
    tObject(std::vector<std::vector<Cell*>>& board);
    bool insert();
    bool rotate(std::string dirction);


};

#endif



