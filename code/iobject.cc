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

        for (int i = 1; i <= 3; i++) {
            deleteCell(getCells()[i]);
        }

        for (int i = 1; i <= 3; i++) {
            getBoard()[axisRow + i][axisCol]->setChar('I');
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

        for (int i = 1; i <= 3; i++) {
            deleteCell(getCells()[i]);
        }

        for (int i = 1; i <= 3; i++) {
            getBoard()[axisRow][axisCol + i]->setChar('I');
        }
        

    }
}

