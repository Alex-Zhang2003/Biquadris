#include "singleobject.h"

SingleObject::SingleObject(std::vector<std::vector<Cell*>>& board): Object{board}, rotatePos{0} {}

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

