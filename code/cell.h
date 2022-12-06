#ifndef CELL_H
#define CELL_H

class Cell {
    const int col;
    const int row;
    char val;
    bool empty;

public:
    Cell(int row, int col, char c);
    bool isEmpty() const;
    void setEmpty();
    char getChar() const;
    void setChar(char val);
    int getRow() const;
    int getCol() const;
    ~Cell();
};


#endif




