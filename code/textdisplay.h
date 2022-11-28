// Concrete Observer
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "absdisplay.h"
#include "player.h"

class TextDisplay : public ABSDisplay {
    Player* player1;
    Player* player2;
    int HiScore;

public:
    TextDisplay(Player* player1, Player* player2, int HiScore);
    void printTitle();
    void printBoard();
    void setNextOb(char*** next, char val, int start);
    void printNextOb(char*** next);
    void notify() override;
    ~TextDisplay();
};



#endif



