// Concrete Observer
#ifndef GRAPHDISPLAY_H
#define GRAPHDISPLAY_H
#include "absdisplay.h"
#include "window.h"
#include "player.h"

class GraphDisplay : public ABSDisplay {
    Player* player1;
    Player* player2;
    Xwindow* theScreen;
    int HiScore;
public:
    GraphDisplay(Player* player1, Player* player2);
    void printTitle();
    void setColor(int x, int y, char c);
    void printBoard();
    void printNextOb(char next, int start);
    void notify() override;
    ~GraphDisplay();
};


#endif



