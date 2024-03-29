#include "jobject.h"

jObject::jObject(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level): Object{board, level}, rotatePos{0} {}

bool jObject::insert() {
    // if (getBoard()[2][0]->isEmpty()) {
        for (int i = 0; i < 3; i++) {
            if (getBoard()[3][i]->isEmpty() == false) {
                return false;
            }
        }

        getCells().push_back(getBoard()[2][0]);
        getCells().back()->setChar('J');

        for (int i = 0; i < 3; i++) {
            getCells().push_back(getBoard()[3][i]);
            getCells().back()->setChar('J');
        }
        return true;
}

bool jObject::rotate(std::string direction) {

    int axisRow;
    int axisCol;

    if (direction == "cw") {

        switch (rotatePos){
            
        case 0:

            axisRow = getCells()[1]->getRow();
            axisCol = getCells()[1]->getCol();

            if (getBoard()[axisRow - 2][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 2][axisCol + 1]);
            getCells().back()->setChar('J');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow - i][axisCol]);
                getCells().back()->setChar('J');
            }
            rotatePos = 3;
            return true;

        case 1:

            axisRow = getCells()[0]->getRow();
            axisCol = getCells()[0]->getCol();

            if (getBoard()[axisRow - 1][axisCol]->isEmpty() == false) {
                return false;
            }

            if (axisCol + 2 >= 11 || getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 1][axisCol]);
            getCells().back()->setChar('J');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow][axisCol + i]);
                getCells().back()->setChar('J');
            }
            rotatePos = 0;
            return true;
            
        case 2:

            axisRow = getCells()[3]->getRow() + 1;
            axisCol = getCells()[3]->getCol();

            if (getBoard()[axisRow][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol]);
            getCells().back()->setChar('J');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow - i][axisCol + 1]);
                getCells().back()->setChar('J');
            }
            rotatePos = 1;
            return true;

        case 3:

            axisRow = getCells()[3]->getRow();
            axisCol = getCells()[3]->getCol();

            if (axisCol + 2 >=11 || getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 1][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol + 2]);
            getCells().back()->setChar('J');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow - 1][axisCol + i]);
                getCells().back()->setChar('J');
            }
            rotatePos = 2;
            return true;
        }

    } else if (direction == "ccw") {

        switch (rotatePos){
            
        case 0:

            axisRow = getCells()[1]->getRow();
            axisCol = getCells()[1]->getCol();

            if (getBoard()[axisRow - 1][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol]);
            getCells().back()->setChar('J');

            for (int i = 0; i <= 2; i++) {
                getCells().push_back(getBoard()[axisRow - i][axisCol + 1]);
                getCells().back()->setChar('J');
            }
            rotatePos = 1;
            return true;

        case 1:

            axisRow = getCells()[0]->getRow();
            axisCol = getCells()[0]->getCol();

            if (getBoard()[axisRow - 1][axisCol]->isEmpty() == false) {
                return false;
            }

            if (axisCol + 2 >= 11 || getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol + 2]);
            getCells().back()->setChar('J');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow - 1][axisCol + i]);
                getCells().back()->setChar('J');
            }
            rotatePos = 2;
            return true;
            
        case 2:

            axisRow = getCells()[0]->getRow();
            axisCol = getCells()[0]->getCol() - 2;

            if (getBoard()[axisRow][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 2][axisCol + 1]);
            getCells().back()->setChar('J');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow - i][axisCol]);
                getCells().back()->setChar('J');
            }
            rotatePos = 3;
            return true;

        case 3:

            axisRow = getCells()[3]->getRow();
            axisCol = getCells()[3]->getCol();

            if (axisCol + 2 >= 11 || getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 1][axisCol]);
            getCells().back()->setChar('J');

            for (int i = 0; i <= 2; i++) {
                getCells().push_back(getBoard()[axisRow][axisCol + i]);
                getCells().back()->setChar('J');
            }
            rotatePos = 0;
            return true;
        }
        
    }
    return false;

}

char jObject::getObjType() {
    return 'J';
}


