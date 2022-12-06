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

Player::Player(int levelNum, bool random, std::string fileName, int seed): 
    levelNum{levelNum}, score{0}, stepCount{0}, heavy{0}, blind{false}, curObj{nullptr}, dropped{false}, seed{seed}, 
    fileName{fileName}, random{random}, curObjType{'\0'}, dead{false}, revived{false}, scoreDouble{false}, noscore{false} {
 
    switch (levelNum) {
        case 0:
            level = std::make_unique<LevelZero> (levelNum, fileName);
            break;
        case 1:
            level = std::make_unique<LevelOne> (levelNum, seed);
            break;
        case 2:
            level = std::make_unique<LevelTwo> (levelNum, seed);
            break;
        case 3:
            level = std::make_unique<LevelThree> (levelNum, seed, random, fileName);
            break;
        case 4:
            level = std::make_unique<LevelFour> (levelNum, seed, random, fileName);
            break;
    }
    board = std::vector<std::vector<std::shared_ptr<Cell>>> (18);
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            board[i].push_back(std::make_shared<Cell> (i, j, '\0'));
        }
    }

    if (levelNum >= 3) {
        heavy = 1;
    }

    nextObj = level->generate();
}

Player::~Player() {}

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
    levelNum += num;
    if (levelNum > 4) {
        levelNum = 4;
    }  
    switch (levelNum) {
        case 1:
            level = std::make_unique<LevelOne> (levelNum, seed);
            break;
        case 2:
            level = std::make_unique<LevelTwo> (levelNum, seed);
            break;
        case 3:
            level = std::make_unique<LevelThree> (levelNum, seed, random, fileName);
            break;
        case 4:
            level = std::make_unique<LevelFour> (levelNum, seed, random, fileName);
            break;
    }
}
void Player::leveldown(int num){
    levelNum -= num;
    if (levelNum < 0) {
        levelNum = 0;
    } 
    switch (levelNum) {
        case 0:
            level = std::make_unique<LevelZero> (levelNum, fileName);
            break;
        case 1:
            level = std::make_unique<LevelOne> (levelNum, seed);
            break;
        case 2:
            level = std::make_unique<LevelTwo>(levelNum, seed);
            break;
        case 3:
            level = std::make_unique<LevelThree> (levelNum, seed, random, fileName);
            break;
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

// void Player::clear(){
//     for (auto it : board) {
//         for (auto jt: it) {
//             jt->setEmpty();
//         }
//     }

//     objects.clear();
// }

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
    for (int i = len - 1; i >= 0; i--) {
        for (int j = rows[i]; j >= 3; j--) {
            for (int k = 0; k < 11; k++) {
                if (board[j - 1][k]->isEmpty()) {
                    board[j][k]->setEmpty();
                } else {
                    board[j][k]->setChar(board[j - 1][k]->getChar());
                }
            }
        }
    }
}

void Player::updateScore(std::vector<int> rows){
    if (rows.size() > 0) {
        if (scoreDouble) {
            score += 2 * (rows.size() + levelNum) * (rows.size() + levelNum);
        } else if (!noscore) {
            score += (rows.size() + levelNum) * (rows.size() + levelNum);
        }
        int idx = 0;
        for (auto it : objects) {
            if (it->isGone()) {
                if (scoreDouble) {
                    score += 2 * it->getScore();
                } else if (!noscore) {
                    score += it->getScore();
                } else {
                    it->getScore();
                }
            }
            idx++;
        }
        scoreDouble = false;
        noscore = false;
    }
}

std::shared_ptr<Object> Player::createNewObj(char obj) {
    std::shared_ptr<Object> tmp;

    if (obj == 'I') {
        tmp = std::make_shared<iObject> (board, levelNum);
    } else if (obj == 'J') {
        tmp = std::make_shared<jObject> (board, levelNum);
    } else if (obj == 'L') {
        tmp = std::make_shared<lObject> (board, levelNum);
    } else if (obj == 'T') {
        tmp = std::make_shared<tObject> (board, levelNum);
    } else if (obj == 'S') {
        tmp = std::make_shared<sObject> (board, levelNum);
    } else if (obj == 'Z') {
        tmp = std::make_shared<zObject> (board, levelNum);
    } else if (obj == 'O') {
        tmp = std::make_shared<oObject> (board, levelNum);
    }
    return tmp;
}

void Player::updateObj() {
    stepCount++;
    curObj = createNewObj(nextObj);
    curObjType = nextObj;
    nextObj = level->generate();
    dropped = false;
    if (levelNum == 4 && stepCount >= 5) {
        stepCount = 0;
        spawnSingleObj();
    }
}

void Player::updateNext() {
    nextObj = level->generate();
}

void Player::spawnSingleObj() {
    std::shared_ptr<SingleObject> single = std::make_shared<SingleObject> (board, 4);
    if (!single->insert()) {
        dead = true;
    } else {
        single->drop();
        objects.push_back(single);
    }
}

bool Player::insert() {
    if (!curObj->insert()) {
        dead = true;
    } else {
        objects.push_back(curObj);
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
    if (levelNum >= 3) {
        random = true;
        level->setRandom();
    }
}

void Player::unsetRandom(){
    if (levelNum >= 3) {
        random = false;
        level->noRandom();
    }
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
    }
    curObj = createNewObj(obj);
    curObjType = obj;
    insert();
}

char Player::getCurObj() {
    return curObjType;
}

bool Player::isDead() {
    return dead;
}

bool Player::canRevive() {
    return !revived;
}

void Player::doRevive() {
    revived = true;
    dead = false;
    dropped = false;
    score /= 2;
    
    std::vector<int> rows;
    for (int i = 10; i >= 0; i--) {
        rows.push_back(i);
        for (int j = 0; j < 11; j++) {
            board[i][j]->setEmpty();
        }
    }

    for (auto it : objects) {
        it->getScore();
    }
    insert();
}

void Player::setDouble() {
    scoreDouble = true;
}

void Player::setNoScore() {
    noscore = true;
}



