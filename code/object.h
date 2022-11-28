#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"
#include <string>
#include <vector>


class Object {

    std::vector<std::vector<Cell*>>& board;
    std::vector<Cell*> cells;
    bool dropped;
    int score;
    
public:

    Object(std::vector<std::vector<Cell*>>& board, int level);
    bool left();
    bool right();
    bool down();
    bool drop();
    bool placed();
    virtual bool insert() = 0;
    virtual bool rotate(std::string dirction) = 0;
    bool isDropped() const;
    bool isGone();
    int getScore();

protected: 

    std::vector<std::vector<Cell*>>& getBoard() const;
    std::vector<Cell*>& getCells();
    bool contain(Cell* cell);
};



#endif



