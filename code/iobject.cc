#include "iobject.h"
#include <iostream>

iObject::iObject(std::vector<std::vector<Cell*>>& board, int level): Object{board, level}, rotatePos{0} {}

bool iObject::insert() {
    int tmpRow = 3;

    for (int tmpCol = 0; tmpCol < 4; tmpCol++) {
        if (getBoard()[tmpRow][tmpCol]->isEmpty() == false) {
            std::cout << "cannot place I at col " << tmpCol << std::endl;
            return false;
        }
    }

    for (int tmpCol = 0; tmpCol < 4; tmpCol++) {
        getBoard()[tmpRow][tmpCol]->setChar('I');
        getCells().push_back(getBoard()[tmpRow][tmpCol]);
    }

    std::cout << "placed I" << std::endl;
    return true;
}

bool iObject::rotate(std::string dirction){
    if (rotatePos == 0){
        rotatePos = 1;
        int axisCol = getCells()[0]->getCol();
        int axisRow = getCells()[0]->getRow();

        for (int i = 1; i <= 3; i++) {
            if (axisRow < 0 || axisRow >= 18) {
                return false;
            }

            if (!getBoard()[axisRow + i][axisCol]->isEmpty()) {
                return false;
            }
        }

        for (auto it : getCells()) {
            it->setEmpty();
        }
        getCells().clear();

        for (int i = 0; i <= 3; i++) {
            getCells().push_back(getBoard()[axisRow - i][axisCol]);
            getCells().back()->setChar('I');
        }

        return true;

    } else if (rotatePos == 1) {
        rotatePos = 0;
        int axisCol = getCells()[0]->getCol();
        int axisRow = getCells()[0]->getRow();

        for (int i = 1; i <= 3; i++) {
            if (axisCol < 0 || axisCol >= 11) {
                return false;
            }

            if (!getBoard()[axisRow][axisCol + i]->isEmpty()) {
                return false;
            }
        }

        for (auto it : getCells()) {
            it->setEmpty();
        }
        getCells().clear();

        for (int i = 0; i <= 3; i++) {
            getCells().push_back(getBoard()[axisRow][axisCol + i]);
            getCells().back()->setChar('I');
        } 
        return true; 
    }
}

