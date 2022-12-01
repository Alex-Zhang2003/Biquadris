#include "cell.h"


Cell::Cell(int row, int col, char c):
    col{col}, row{row}, val{c}, empty{true} {}

bool Cell::isEmpty() const {
    return empty;
}

char Cell::getChar() const {
    return val;
}

void Cell::setChar(char val) {
    this->val = val;
    empty = false;
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
}

 void Cell::setEmpty() {
    empty = true;
    val = '\0';
 }

Cell::~Cell() {}

