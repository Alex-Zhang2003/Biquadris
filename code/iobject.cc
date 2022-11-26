#include "iobject.h"

iObject::iObject(std::vector<std::vector<Cell*>>& board): Object{board} {}

bool iObject::insert() {
    int tmpRow = 3;

    for (int tmpCol = 0; tmpCol < 4; tmpCol++) {
        if (board[tmpRow][tmpCol])
    }
}

