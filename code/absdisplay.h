// Abstract Observer Class
#ifndef ABSDISPLAY_H
#define ABSDISPLAY_H
#include "absplayer.h"

class ABSPlayer;

class ABSDisplay {

public:
    virtual void notify() = 0;
    virtual ~ABSDisplay() = default;
    virtual void updateBoard() = 0;
};


#endif





