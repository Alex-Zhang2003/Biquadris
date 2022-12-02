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
    levelNum{levelNum}, score{0}, stepCount{0}, heavy{0}, blind{false}, curObj{nullptr}, dropped{false}, seed{seed}, fileName{fileName}, random{random}, curObjType{'\0'}, dead{false} {
 
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
    if (levelNum >= 3) {
        heavy = 1;
    }
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
        if(!curObj->down()) {
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
    if (blind && row >= 2 && row < 12 && col >= 2 && col < 9) {
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
    if (heavy == 1 || heavy == 0) {
        heavy += num;
    }
}
void Player::setBlind() {
    blind = true;
}
void Player::setForced(char obj){
    nextObj = obj;
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

int Player::update(){
    std::vector<int> rows = removeRows();
    updateScore(rows);
    dropRows(rows);
    if (blind) {
        blind = false;
    }
    return rows.size();
}

std::vector<int> Player::removeRows(){
    std::vector<int> rows;
    for (int i = 17; i >= 3; i--) {
        if (rowEmpty(i)) {
            rows.push_back(i);
            for (int j = 0; j < 11; j++) {
                board[i][j]->setEmpty();
            }
        }
    }
    if (rows.size() > 0) {
        stepCount = 0;
    }
    return rows;
}

bool Player::rowEmpty(int row){
    for (int j = 0; j < 11; j++) {
        if (board[row][j]->isEmpty()) {
            return false;
        }
    }
    return true;
}

void Player::dropRows(std::vector<int> rows) {
    int len = rows.size();
    for (int i = 0; i < len; i++) {
        for (int j = rows.back(); j >= 3; j--) {
            for (int k = 0; k < 11; k++) {
                if (board[j - 1][k]->isEmpty()) {
                    board[j][k]->setEmpty();
                } else {
                    board[j][k]->setChar(board[j - 1][k]->getChar());
                }
            }
        }
        rows.pop_back();
    }
}

void Player::updateScore(std::vector<int> rows){
    if (rows.size() > 0) {
        score += (rows.size() + levelNum) * (rows.size() + levelNum);
        int idx = 0;
        for (auto it : objects) {
            if (it->isGone()) {
                score += it->getScore();
                objects.erase(objects.begin() + idx);
                delete it;
            }
            idx++;
        }
    }
}

Object* Player::createNewObj(char obj) {
    Object* tmp = nullptr;

    if (obj == 'I') {
        tmp = new iObject(board, levelNum);
    } else if (obj == 'J') {
        tmp = new jObject(board, levelNum);
    } else if (obj == 'L') {
        tmp = new lObject(board, levelNum);
    } else if (obj == 'T') {
        tmp = new tObject(board, levelNum);
    } else if (obj == 'S') {
        tmp = new sObject(board, levelNum);
    } else if (obj == 'Z') {
        tmp = new zObject(board, levelNum);
    } else if (obj == 'O') {
        tmp = new oObject(board, levelNum);
    }
    return tmp;
}

void Player::updateObj() {
    stepCount++;
    curObj = createNewObj(nextObj);
    curObjType = nextObj;
    objects.push_back(curObj);
     
    nextObj = level->generate();
    dropped = false;
    if (levelNum == 4 && stepCount >= 5) {
        stepCount = 0;
        spawnSingleObj();
    }
}

void Player::spawnSingleObj() {
    Object* single = new SingleObject(board, 4);
    if (!single->insert()) {
        dead = true;
        delete single;
    } else {
        single->drop();
        objects.push_back(single);
    }
}

bool Player::insert() {
    if (!curObj->insert()) {
        dead = true;
    }
    return !dead;
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
    if (curObj != nullptr) {
        curObj->clear();
        objects.pop_back();
        delete curObj;
    }
    std::cout << obj << std::endl;
    curObj = createNewObj(obj);
    objects.push_back(curObj);
    curObjType = obj;
    insert();
}

char Player::getCurObj() {
    return curObjType;
}

bool Player::isDead() {
    return dead;
}
