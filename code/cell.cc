#include "cell.h"


Cell::Cell(int row, int col, char c):
    row{row}, col{col}, val{c}, placed{false} {}

bool Cell::isEmpty() const {
    return placed;
}

char Cell::getChar() const {
    return val;
}

void Cell::setChar(char val) {
    this->val = val;
    placed = true;
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
}

 void Cell::setEmpty() {
    placed = false;
    val = '\0';
 }

Cell::~Cell() {}

