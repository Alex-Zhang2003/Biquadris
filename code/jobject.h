#ifndef JOBJECT_H
#define JOBJECT_H
#include "object.h"

class jObject : public Object{

// rotatePos = 0 :

    //    J
    //    JJJ

    // rotatePos = 1:

    //      J
    //      J
    //     JJ

    // rotatePos = 2:

    //     JJJ
    //       J

    // rotatePos = 3:
    //     JJ
    //     J
    //     J

    int rotatePos;

public:

    
    jObject(std::vector<std::vector<Cell*>>& board, int level);
    bool insert();
    bool rotate(std::string direction);


};

#endif



