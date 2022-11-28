#include "lobject.h"

lObject::lObject(std::vector<std::vector<Cell*>>& board): Object{board}, rotatePos{0} {}

bool lObject::insert() {
    if (getBoard()[2][2]->isEmpty()) {
        for (int i = 0; i < 3; i++) {
            if (getBoard()[3][i]->isEmpty() == false) {
                return false;
            }
        }

        getCells().push_back(getBoard()[2][2]);
        getCells().back()->setChar('L');

        for (int i = 0; i < 3; i++) {
            getCells().push_back(getBoard()[3][2 - i]);
            getCells().back()->setChar('L');
        }

        return true;

    } 
    return false;
}

bool lObject::rotate(std::string direction) {

    if (direction == "cw") {

        switch (rotatePos){
            
        case 0:

            rotatePos = 3;

            int axisRow = getCells()[3]->getRow();
            int axisCol = getCells()[3]->getCol();

            if (getBoard()[axisRow - 1][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol + 1]);
            getCells().back()->setChar('T');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow - i][axisCol]);
                getCells().back()->setChar('L');
            }

            return true;

        case 1:

            rotatePos = 0;

            int axisRow = getCells()[3]->getRow();
            int axisCol = getCells()[3]->getCol() - 1;

            if (getBoard()[axisRow][axisCol]->isEmpty() == false) {
                return false;
            }

            if (axisCol + 2 >= 11 || getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 1][axisCol + 2]);
            getCells().back()->setChar('L');

            for (int i = 2; i >= 0; i++) {
                getCells().push_back(getBoard()[axisRow][axisCol + i]);
                getCells().back()->setChar('L');
            }
            return true;
            
        case 2:

            rotatePos = 1;

            int axisRow = getCells()[0]->getRow();
            int axisCol = getCells()[0]->getCol();

            if (getBoard()[axisRow - 2][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 2][axisCol]);
            getCells().back()->setChar('L');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow + i][axisCol + 1]);
                getCells().back()->setChar('L');
            }
            return true;

        case 3:

            rotatePos = 2;

            int axisRow = getCells()[1]->getRow();
            int axisCol = getCells()[1]->getCol();

            if (axisCol + 2 >=11 || getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 1][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol]);
            getCells().back()->setChar('L');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow - 1][axisCol + i]);
                getCells().back()->setChar('L');
            }
            return true;
        }

    } else if (direction == "ccw") {

        switch (rotatePos){
            
        case 0:
        
            rotatePos = 1;

            int axisRow = getCells()[3]->getRow();
            int axisCol = getCells()[3]->getCol();

            if (getBoard()[axisRow - 1][axisCol + 1]->isEmpty() == false) {
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

            getCells().push_back(getBoard()[axisRow - 2][axisCol]);
            getCells().back()->setChar('L');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow - i][axisCol + 1]);
                getCells().back()->setChar('L');
            }

            return true;

        case 1:

            rotatePos = 2;

            int axisRow = getCells()[0]->getRow() + 2;
            int axisCol = getCells()[0]->getCol();

            if (getBoard()[axisRow][axisCol]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 1][axisCol]->isEmpty() == false) {
                return false;
            }

            if (axisCol + 2 >= 11 || getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol]);
            getCells().back()->setChar('L');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow - 1][axisCol + i]);
                getCells().back()->setChar('L');
            }
            return true;
            
        case 2:

            rotatePos = 3;

            int axisRow = getCells()[0]->getRow();
            int axisCol = getCells()[0]->getCol();

            if (getBoard()[axisRow][axisCol + 1]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 2][axisCol]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow][axisCol + 1]);
            getCells().back()->setChar('L');

            for (int i = 0; i < 3; i++) {
                getCells().push_back(getBoard()[axisRow - i][axisCol]);
                getCells().back()->setChar('L');
            }
            return true;

        case 3:

            rotatePos = 0;

            int axisRow = getCells()[1]->getRow();
            int axisCol = getCells()[1]->getCol();

            if (axisCol + 2 >=11 || getBoard()[axisRow][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            if (getBoard()[axisRow - 1][axisCol + 2]->isEmpty() == false) {
                return false;
            }

            for (auto it : getCells()) {
                it->setEmpty();
            }
            getCells().clear();

            getCells().push_back(getBoard()[axisRow - 1][axisCol + 2]);
            getCells().back()->setChar('L');

            for (int i = 2; i >= 0; i--) {
                getCells().push_back(getBoard()[axisRow][axisCol + i]);
                getCells().back()->setChar('L');
            }
            return true;
        }
        
    }

}
