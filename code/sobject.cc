#include "sobject.h"

sObject::sObject(std::vector<std::vector<Cell*>>& board, int level): Object{board, level}, rotatePos{0} {}

bool sObject::insert() {
    for (int i = 0; i < 2; i++) {
        if (getBoard()[2][i + 1]->isEmpty() == false) {
            return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (getBoard()[3][i]->isEmpty() == false) {
            return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        getCells().push_back(getBoard()[3][i]);
        getCells().back()->setChar('S');
    }
    for (int i = 0; i < 2; i++) {
        getCells().push_back(getBoard()[2][i + 1]);
        getCells().back()->setChar('S');
    }
    return true;
}

bool sObject::rotate(std::string direction) {
    if (rotatePos == 0) {
        rotatePos = 1;

        int axisRow = getCells()[0]->getRow();
        int axisCol = getCells()[0]->getCol();

        if (getBoard()[axisRow - 1][axisCol]->isEmpty() == false) {
            return false;
        }

        if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
            return false;
        }

        for (auto it : getCells()) {
            it->setEmpty();
        }
        getCells().clear();

        for (int i = 2; i > 0; i--) {
            getCells().push_back(getBoard()[axisRow - i][axisCol]);
            getCells().back()->setChar('S');
        }
        for (int i = 1; i >= 0; i--) {
            getCells().push_back(getBoard()[axisRow - i][axisCol + 1]);
            getCells().back()->setChar('S');
        }

        return true;   

    } else if (rotatePos == 1){
        rotatePos = 0;

        int axisRow = getCells()[1]->getRow() + 1;
        int axisCol = getCells()[1]->getCol();

        if (axisCol + 2 >= 11 || getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
            return false;
        }

        if (getBoard()[axisRow][axisCol]->isEmpty() == false) {
            return false;
        }

        for (auto it : getCells()) {
            it->setEmpty();
        }
        getCells().clear();

        for (int i = 0; i < 2; i++) {
            getCells().push_back(getBoard()[axisRow][axisCol + i]);
            getCells().back()->setChar('S');
        }
        for (int i = 1; i < 3; i++) {
            getCells().push_back(getBoard()[axisRow - 1][axisCol + i]);
            getCells().back()->setChar('S');
        }

        return true;

    }
}






