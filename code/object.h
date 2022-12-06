#ifndef OBJECT_H
#define OBJECT_H

#include "cell.h"
#include <string>
#include <vector>
#include <memory>

class Object {

    std::vector<std::vector<std::shared_ptr<Cell>>>& board;
    std::vector<std::shared_ptr<Cell>> cells;
    bool dropped;
    int score;
    bool gone;
    
public:

    Object(std::vector<std::vector<std::shared_ptr<Cell>>>& board, int level);
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
    virtual char getObjType() = 0;

protected: 

    std::vector<std::vector<std::shared_ptr<Cell>>>& getBoard() const;
    std::vector<std::shared_ptr<Cell>>& getCells();
    bool contain(std::shared_ptr<Cell> cell);
};



#endif





