// Concrete Observer
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "absdisplay.h"
#include "player.h"

class TextDisplay : public ABSDisplay {
    Player* player1;
    Player* player2;
    int HiScore;
    char** next;

public:
    TextDisplay(Player* player1, Player* player2);
    void updateHiScore(int score);
    void printTitle();
    void printBoard();
    void setNextOb(char val, int start);
    void printNextOb();
    void notify() override;
    ~TextDisplay();
};



#endif



