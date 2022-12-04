// Concrete Observer
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "absdisplay.h"
#include "player.h"

class Game;

class TextDisplay : public ABSDisplay {
    Game* game;
    Player* player1;
    Player* player2;
    int HiScore;
    char** next;

public:
    TextDisplay(Player* player1, Player* player2, Game* game);
    void printTitle();
    void printBoard();
    void setNextOb(char val, int start);
    void printNextOb();
    void notify() override;
    void updateBoard();
    ~TextDisplay();
};



#endif



