// Concrete Observer
#ifndef GRAPHDISPLAY_H
#define GRAPHDISPLAY_H
#include "absdisplay.h"
#include "window.h"

class GraphDisplay : public ABSDisplay {
    Player* player1;
    Player* player2;
    Xwindow* theScreen;
    int HiScore;
public:
    GraphDisplay(Player* player1, Player* player2, Xwindow* theScreen, int HiScore);
    void printTitle() override;
    void printBoard() override;
    void setNextOb(char*** next, char val, int start) override;
    void printNextOb(char*** next) override;
    void notify() override;
    ~GraphDisplay();
};


#endif



