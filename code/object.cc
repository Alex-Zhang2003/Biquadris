#include "object.h"

Object::Object(std::vector<std::vector<Cell*>>& board, int level): board{board}, score{(level + 1) * (level + 1)}{
    dropped = false;
}

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
        tmp.back()->setChar(board[row][col + 1]->getChar());
        board[row][col + 1]->setEmpty();
    }

    cells = tmp;
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
        tmp.back()->setChar(board[row][col - 1]->getChar());
        board[row][col - 1]->setEmpty();
    }

    cells = tmp;
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
        tmp.back()->setChar(board[row - 1][col]->getChar());
        board[row - 1][col]->setEmpty();
    }

    cells = tmp;
    return true;

}

bool Object::drop(){

    while (dropped == true) {
        dropped = !down();
    }

}

bool Object::placed(){

    return dropped;

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
        if (it->isEmpty() == false) {
            return false;
        }
    }
    return true;
}

int Object::getScore() {
    return score;
}
