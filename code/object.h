#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"
#include <string>
#include <vector>


class Object {

    std::vector<std::vector<Cell*>>& board;
    std::vector<Cell*> cells;
    int num;
    bool dropped;
    
public:

    Object(std::vector<std::vector<Cell*>>& board);
    bool left();
    bool right();
    bool down();
    bool drop();
    bool placed();
    virtual bool insert() = 0;
    virtual bool rotate(std::string dirction) = 0;

protected: 

    std::vector<std::vector<Cell*>>& getBoard() const;
    std::vector<Cell*>& getCells();
    int getNum() const;
    void deleteCell(Cell* val);
    bool isDropped() const;
};



#endif



