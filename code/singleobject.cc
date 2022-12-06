#include "singleobject.h"

SingleObject::SingleObject(std::vector<std::vector<Cell*>>& board, int level): Object{board, level}, rotatePos{0} {}

SingleObject::~SingleObject(){}

bool SingleObject::insert() {

    if (getBoard()[3][5]->isEmpty() == false) {
        return false;
    }
    getBoard()[3][5]->setChar('*');
    getCells().push_back(getBoard()[3][5]);
    return true;
}

bool SingleObject::rotate(std::string dirction){
    return true;
}

char SingleObject::getObjType(){
    return '*';
}



