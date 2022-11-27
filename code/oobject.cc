#include "oobject.h"

oObject::oObject(std::vector<std::vector<Cell*>>& board): Object{board}, rotatePos{0} {}

bool oObject::insert(){

    int tmpRow = 2;

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            if (getBoard()[tmpRow + row][col]->isEmpty() == false) {
            return false;
        }
        }
    }

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            getBoard()[tmpRow + row][col]->setChar('O');
            getCells().push_back(getBoard()[tmpRow + row][col]);
        }
    }
    
    return true;

}

bool oObject::rotate(std::string dirction){
    return true;
}


