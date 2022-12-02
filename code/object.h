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
    bool gone;
    
public:

    Object(std::vector<std::vector<Cell*>>& board, int level);
    virtual ~Object();
    bool left();
    bool right();
    bool down();
    void drop();
    virtual bool insert() = 0;
    virtual bool rotate(std::string dirction) = 0;
    bool isDropped() const;
    bool isGone();
    int getScore();
    void clear();

protected: 

    std::vector<std::vector<Cell*>>& getBoard() const;
    std::vector<Cell*>& getCells();
    bool contain(Cell* cell);
};



#endif



