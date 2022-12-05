// Concrete Observer
#ifndef GRAPHDISPLAY_H
#define GRAPHDISPLAY_H
#include "absdisplay.h"
#include "window.h"
#include "player.h"

class Game;

class GraphDisplay : public ABSDisplay {
    Game* game;
    Player* player1;
    Player* player2;
    Xwindow* theScreen;
    bool scoreUpdated;
    char** board1;
    char** board2;
    int score1;
    int score2;
    int level1;
    int level2;
    int hiScore;

public:
    GraphDisplay(Player* player1, Player* player2, Game* game);
    void printTitle();
    void setColor(int x, int y, char c);
    void printBoard();
    void printNextOb(char next, int start);
    void notify() override;
    ~GraphDisplay();
    void updateBoard();
};


#endif



