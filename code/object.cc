#include "object.h"

Object::Object(std::vector<std::vector<Cell*>>& board, int level): board{board}, score{(level + 1) * (level + 1)}{
    dropped = false;
}

bool Object::left(){
    for (auto it : cells) {
        int col = it->getCol() + 1;
        int row = it->getRow();

        if (col >= board[0].size() || board[row][col]->isEmpty() == false) {
            return false;
        }
    }

    for (auto it : cells) {
        int col = it->getCol() + 1;
        int row = it->getRow();
        board[row][col]->setChar(board[row][col - 1]->getChar());
        board[row][col - 1]->setEmpty();
    }
    return true;
}

bool Object::right(){

    for (auto it : cells) {
        int col = it->getCol() - 1;
        int row = it->getRow();

        if (col < 0 || board[row][col]->isEmpty() == false) {
            return false;
        }
    }

    for (auto it : cells) {
        int col = it->getCol() - 1;
        int row = it->getRow();
        board[row][col]->setChar(board[row][col + 1]->getChar());
        board[row][col + 1]->setEmpty();
    }
    return true;

}

bool Object::down(){

    for (auto it : cells) {
        int col = it->getCol();
        int row = it->getRow() + 1;

        if (row >= board.size() || board[row][col]->isEmpty() == false) {
            return false;
        }

    }

    for (auto it : cells) {
        int col = it->getCol();
        int row = it->getRow() + 1;
        board[row][col]->setChar(board[row - 1][col]->getChar());
        board[row - 1][col]->setEmpty();
    }
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
