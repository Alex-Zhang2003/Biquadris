// Observer
#ifndef ABSDISPLAY_H
#define ABSDISPLAY_H
#include "absplayer.h"

class ABSPlayer;

class ABSDisplay {

public:
    virtual void printTitle() = 0;
    virtual void printBoard() = 0;
    virtual void setNextOb(char*** next, char val, int start) = 0;
    virtual void printNextOb(char*** next) = 0;
    virtual void notify() = 0;
    virtual ~ABSDisplay() = default;
};


#endif



