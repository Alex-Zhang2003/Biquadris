

class Cell {
    int x;
    int y;
    char c;
    bool placed;
public:
    Cell(int x, int y, char c, bool placed);
    bool isEmpty() const;
    char getChar() const;
    void setChar(char val);
    int getRow() const;
    void setRow(int row);
    int getCol() const;
    void setCol(int col);
    ~Cell();
};

