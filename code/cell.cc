#include "cell.h"


Cell::Cell(int x, int y, char c, bool placed):
    x{x}, y{y}, c{c}, placed{placed} {}

bool Cell::isEmpty() const {
    return placed;
}

char Cell::getChar() const {
    if (!isEmpty()) return c;
}

void Cell::setChar(char val) {
    c = val;
    placed = true;
}

int Cell::getRow() const {
    return x;
}

void Cell::setRow(int row) {
    x = row;
}

int Cell::getCol() const {
    return y;
}

void Cell::setCol(int col) {
    y = col;
}

Cell::~Cell() { }



