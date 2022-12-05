#include "iobject.h"

iObject::iObject(std::vector<std::vector<Cell*>>& board, int level): Object{board, level}, rotatePos{0} {}

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
        int axisCol = getCells()[0]->getCol();
        int axisRow = getCells()[0]->getRow();

        for (int i = 1; i <= 3; i++) {
            if (axisRow - i < 0) {
                return false;
            }

            if (!getBoard()[axisRow - i][axisCol]->isEmpty()) {
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
        rotatePos = 1;
        return true;

    } else if (rotatePos == 1) {
        int axisCol = getCells()[0]->getCol();
        int axisRow = getCells()[0]->getRow();

        for (int i = 1; i <= 3; i++) {
            if (axisCol + i >= 11) {
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
        rotatePos = 0;
        return true; 
    }

    return false;
}

char iObject::getObjType() {
    return 'I';
}
