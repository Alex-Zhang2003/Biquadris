// Concrete Observer
#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "absdisplay.h"
#include "player.h"
#include <memory>

class Game;

class TextDisplay : public ABSDisplay {
    std::unique_ptr<Game> game;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    int HiScore;
    std::unique_ptr<std::unique_ptr<char[]>[]> next;

public:
    TextDisplay(std::unique_ptr<Player> player1, std::unique_ptr<Player> player2, std::unique_ptr<Game> game);
    void printTitle();
    void printBoard();
    void setNextOb(char val, int start);
    void printNextOb();
    void notify() override;
    void updateBoard();
    ~TextDisplay();
};



#endif





