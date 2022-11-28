// Concrete Subject
#ifndef PLAYER_H
#define PLAYER_H
#include "absplayer.h"
#include "cell.h"
#include "object.h"
#include "level.h"
#include <string>
#include <vector>

class Player : public ABSPlayer{

    std::vector<std::vector<Cell>> board;
    std::vector<Object> objects;
    Level* level;
    int levelNum;
    int score;
    int stepCount;
    int isHeavy;
    bool isBlind;
    char isForced;
    Object* curObj;
    char nextObj;
    bool isDropped;

public:

    void left(int num = 1);
    void right(int num = 1);
    void down(int num = 1);
    void drop();
    void rotate(std::string direction, int num = 1);
    bool isDropped();
    bool isBlind();
    char getNext();
    int getLevel();
    int getScore();
    char getState(int row, int col);
    void levelup();
    void leveldown();
    void setHeavy(int num = 1);
    void setBlind();
    void setForced(char obj);
    void clear();
    bool placeObj();
    void update();








};


#endif



