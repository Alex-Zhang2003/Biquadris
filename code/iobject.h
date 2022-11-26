#ifndef IOBJECT_H
#define IOBJECT_H
#include <object.h>

class iObject : public Object {

    int rotatePos;

public:

    
    iObject(std::vector<std::vector<Cell*>>& board);
    bool insert();
    bool rotate(std::string dirction);


};

#endif



