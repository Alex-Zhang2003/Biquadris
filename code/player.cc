#include "player.h"
#include "level.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"
#include "iobject.h"
#include "lobject.h"
#include "jobject.h"
#include "tobject.h"
#include "sobject.h"
#include "zobject.h"
#include "oobject.h"
#include "singleobject.h"

#include <iostream>

Player::Player(int levelNum, bool random, std::string fileName, int seed): 
    levelNum{levelNum}, score{0}, stepCount{0}, heavy{0}, blind{false}, forced{'\0'}, curObj{nullptr}, dropped{false}, seed{seed}, fileName{fileName}, random{random}, curObjType{'\0'} {
 
    switch (levelNum) {
        case 0:
            level = new LevelZero(levelNum, fileName);
            break;
        case 1:
            level = new LevelOne(levelNum, seed);
            break;
        case 2:
            level = new LevelTwo(levelNum, seed);
            break;
        case 3:
            level = new LevelThree(levelNum, seed, random, fileName);
            break;
        case 4:
            level = new LevelFour(levelNum, seed, random, fileName);
            break;
    }
    board = std::vector<std::vector<Cell*>> (18);
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            board[i].push_back(new Cell(i, j, '\0'));
        }
    }
    nextObj = level->generate();
}

Player::~Player() {

    for (auto it : board) {
        for (auto jt : it) {
            delete jt;
        }
    }

    // add delete object if objects need to be pointers
    for (auto it : objects) {
        delete it;
    }

    delete level;

}

void Player::fall() {
    for (int i = 0; i < heavy; i ++) {
        if(!curObj->drop()) {
            dropped = true;
            return;
        }
    }
}

void Player::left(int num){
    for (int i = 0; i < num; i++) {
        if (!curObj->left()) {
            break;
        }
    }

    fall();
}

void Player::right(int num){
    for (int i = 0; i < num; i++) {
        if (!curObj->right()) {
            break;
        }
    }

    fall();
}

void Player::down(int num){
    for (int i = 0; i < num; i++) {
        if (!curObj->down()) {
            dropped = true;
            break;
        }
    }

    fall();
}

void Player::drop(){
    if (!dropped) {
        while (curObj->down()){}
        dropped = true;
    }
}

void Player::rotate(std::string direction, int num) {
    for (int i = 0; i < num; i++) {
        if (!curObj->rotate(direction)) {
            break;
        }
    }

    fall();
}

bool Player::isDropped() {
    return dropped;
}

bool Player::isBlind() {
    return blind;
}

char Player::getNext() {
    return nextObj;
}
int Player::getLevel() {
    return levelNum;
}

int Player::getScore() {
    return score;
}

char Player::getState(int row, int col) {
    if (blind && row >= 3 && row <= 12 && col >= 3 && col <= 9) {
        return '?';
    } else {
        return board[row][col]->getChar();
    }
}

void Player::levelup(int num) {
    for (int i = 0; i < num; i++) {
        if (num < 4) {
            int next = levelNum + 1;
            levelNum++;
            delete level;
            
            switch (next) {
                case 1:
                    level = new LevelOne(levelNum, seed);
                    break;
                case 2:
                    level = new LevelTwo(levelNum, seed);
                    break;
                case 3:
                    level = new LevelThree(levelNum, seed, random, fileName);
                    if (heavy != 3 && heavy != 1) {
                        heavy++;
                    }
                    break;
                case 4:
                    level = new LevelFour(levelNum, seed, random, fileName);
                    break;
            }
        }
    }
}
void Player::leveldown(int num){
    for (int i = 0; i < num; i++) {
        if (num < 4) {
            int next = levelNum - 1;
            levelNum--;
            delete level;
            
            switch (next) {
                case 0:
                    level = new LevelZero(levelNum, fileName);
                    break;
                case 1:
                    level = new LevelOne(levelNum, seed);
                    break;
                case 2:
                    level = new LevelTwo(levelNum, seed);
                    break;
                case 3:
                    level = new LevelThree(levelNum, seed, random, fileName);
                    break;
            }
        }
    }
}

void Player::setHeavy(int num) {
    heavy += num;
}
void Player::setBlind() {
    blind = true;
}
void Player::setForced(char obj){
    forced = obj;
}

void Player::clear(){
    for (auto it : board) {
        for (auto jt: it) {
            jt->setEmpty();
        }
    }
    for (auto it : objects) {
        delete it;
    }

    objects.clear();

}

bool Player::placeObj(){

    return curObj->insert();

}

void Player::update(){
    std::vector<int> rows = removeRows();
    dropRows(rows);
    updateScore(rows);
}

std::vector<int> Player::removeRows(){
    std::vector<int> rows;
    for (int i = 3; i < 18; i++) {
        bool remove = true;
        for (int j = 0; j < 11; j++) {
            if (board[i][j]->isEmpty() == false) {
                remove = false;
                break;
            }
        }
        if (remove == true) {
            rows.push_back(i);
            for (int j = 0; j < 11; j++) {
                board[i][j]->setEmpty();
            }
        }
    }
    return rows;
}

bool Player::rowEmpty(int row){
    for (int j = 0; j < 11; j++) {
        if (board[row][j]->isEmpty() == false) {
            return false;
        }
    }
    return true;
}

void Player::dropRows(std::vector<int> rows) {
    int len = rows.size();
    for (int i = 0; i < len; i++) {
        for (int j = rows.back(); j > 3; j--) {
            rows.pop_back();
            for (int k = 0; k < 11; k++) {
                Cell* tmp = board[j][k];
                board[j][k] = new Cell(board[j - 1][k]->getRow(), board[j - 1][k]->getCol(), board[j - 1][k]->getChar());
                delete tmp;
            }
        }
    }
}

void Player::updateScore(std::vector<int> rows){
    score += (rows.size() + levelNum) * (rows.size() + levelNum);
    for (auto it : objects) {
        if (it->isGone()) {
            score += it->getScore();
            // consider deleting for better performance ?
        }
    }

}

Object* Player::createNewObj(char obj) {
    Object* tmp = nullptr;
    if (obj == 'I') {
        tmp = new iObject(board, levelNum);
    } else if (nextObj == 'J') {
        tmp = new jObject(board, levelNum);
    } else if (nextObj == 'L') {
        tmp = new lObject(board, levelNum);
    } else if (nextObj == 'T') {
        tmp = new tObject(board, levelNum);
    } else if (nextObj == 'S') {
        tmp = new sObject(board, levelNum);
    } else if (nextObj == 'Z') {
        tmp = new zObject(board, levelNum);
    } else if (nextObj == 'O') {
        tmp = new oObject(board, levelNum);
    }

    return tmp;
}

void Player::updateObj() {

    if (forced != '\0') {
        nextObj = forced;
        forced = '\0';
    }

    curObj = createNewObj(nextObj);
    curObjType = nextObj;
    objects.push_back(curObj);
     
    nextObj = level->generate();
}

bool Player::insert() {
    return (curObj->insert());
}

std::string Player::getFile() {
    return fileName;
}

int Player::getSeed() {
    return seed;
}

void Player::setRandom() {
    random = true;
}

void Player::unsetRandom(){
    random = false;
}

bool Player::isRandom() {
    return random;
}

void Player::changeLevelFile(std::string newFile) {
    level->changeFile(newFile);
}

void Player::replaceCur(char obj) {
    curObj->clear();
    delete curObj;

    curObj = createNewObj(obj);
    curObjType = obj;
    
    //what if cannot insert?
    curObj->insert();
    
}

char Player::getCurObj() {
    return curObjType;
}
