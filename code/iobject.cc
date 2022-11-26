#include "iobject.h"

iObject::iObject(std::vector<std::vector<Cell*>>& board): Object{board}, rotatePos{0} {}

bool iObject::insert() {
    int tmpRow = 3;

    for (int tmpCol = 0; tmpCol < 4; tmpCol++) {
        if (getBoard()[tmpRow][tmpCol]->isEmpty() == false) {
            return false;
        }
    }

    for (int tmpCol = 0; tmpCol < 4; tmpCol++) {
        getBoard()[tmpRow][tmpCol]->setChar('I');
        getCells().push_back(getBoard()[tmpRow][tmpCol]);
    }

    return true;
}

bool iObject::rotate(std::string dirction){
    if (rotatePos == 0){
        rotatePos = 1;



    } else if (rotatePos == 1) {
        rotatePos = 0;

    }
}

