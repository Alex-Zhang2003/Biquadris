#include "object.h"

#include <iostream>

Object::Object(std::vector<std::vector<Cell*>>& board, int level): board{board}, score{(level + 1) * (level + 1)}{
    dropped = false;
}

Object::~Object(){}

bool Object::contain(Cell* cell){
    bool isOwn = false;
    for (auto it : cells) {
        if (it == cell) {
            isOwn = true;
            break;
        }
    }
    return isOwn;

}

bool Object::left(){
    for (auto it : cells) {
        int col = it->getCol() - 1;
        int row = it->getRow();

        if (col < 0) {
            return false;
        }

        if (board[row][col]->isEmpty() == false) {
            if (!contain(board[row][col])) {
                return false;
            }
        }
    }

    std::vector<Cell*> tmp;

    for (auto it : cells) {
        int col = it->getCol() - 1;
        int row = it->getRow();
        tmp.push_back(board[row][col]);
        tmp.back()->setChar(it->getChar());
    }
    std::swap(tmp, cells);

    for (auto it : tmp) {
        if (!contain(it)) {
            it->setEmpty();
        }
    }
    return true;
    
}

bool Object::right(){

    for (auto it : cells) {
        int col = it->getCol() + 1;
        int row = it->getRow();

        if (col >= 11) {
            return false;
        }

        if (board[row][col]->isEmpty() == false) {
            if (!contain(board[row][col])) {
                return false;
            }
        }
    }

    std::vector<Cell*> tmp;

    for (auto it : cells) {
        int col = it->getCol() + 1;
        int row = it->getRow();
        tmp.push_back(board[row][col]);
        tmp.back()->setChar(it->getChar());
    }

    std::swap(tmp, cells);

    for (auto it : tmp) {
        if (!contain(it)) {
            it->setEmpty();
        }
    }
    return true;

}

bool Object::down(){

    for (auto it : cells) {
        int col = it->getCol();
        int row = it->getRow() + 1;

        if (row >= 18) {
            return false;
        }

        if (board[row][col]->isEmpty() == false) {
            if (!contain(board[row][col])) {
                return false;
            }
        }
    }

    std::vector<Cell*> tmp;

    for (auto it : cells) {
        int col = it->getCol();
        int row = it->getRow() + 1;
        tmp.push_back(board[row][col]);
        tmp.back()->setChar(it->getChar());
    }

    std::swap(tmp, cells);

    for (auto it : tmp) {
        if (!contain(it)) {
            it->setEmpty();
        }
    }
    return true;

}

void Object::drop(){

    while (dropped == false) {
        dropped = !down();
    }

}

std::vector<std::vector<Cell*>>& Object::getBoard() const{
    return board;
}

std::vector<Cell*>& Object::getCells() {
    return cells;
}

bool Object::isDropped() const{
    return dropped;
}

bool Object::isGone() {
    for (auto it : cells) {
        if (!it->isEmpty()) {
            std::cout << "row " << it->getRow() << ", col " << it->getCol() << std::endl;
            return false;
        }
    }
    return true;
}

int Object::getScore() {
    return score;
}

void Object::clear() {
    for (auto it : cells) {
        it->setEmpty();
    }
}
