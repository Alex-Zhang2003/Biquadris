#include "graphdisplay.h"
#include <iostream>
#include <string>

GraphDisplay::GraphDisplay(Player *player1, Player *player2):
    player1{player1}, player2{player2}, theScreen {new Xwindow{300, 400}}, HiScore{0}{
    board1 = new char*[18];
    board2 = new char*[18];
    for (int i = 0; i < 18; i++) {
        board1[i] = new char[11];
        board2[i] = new char[11];
        for (int j = 0; j < 11; j++) {
            board1[i][j] = ' ';
            board2[i][j] = ' ';
        }
    }
}

void GraphDisplay::updateHiScore(int score) {
    HiScore = score;
}


void GraphDisplay::printTitle() {
    theScreen->fillRectangle(180, 10, 10, 10, Xwindow::White);
    theScreen->fillRectangle(80, 50, 10, 10, Xwindow::White);
    theScreen->fillRectangle(230, 50, 10, 10, Xwindow::White);
    theScreen->fillRectangle(80, 60, 10, 10, Xwindow::White);
    theScreen->fillRectangle(230, 60, 10, 10, Xwindow::White);
    
    theScreen->drawString(80, 10, "Hi Score: ");
    std::string HiScore_String = std::to_string(HiScore);
    theScreen->drawString(180, 10, HiScore_String);
    theScreen->drawString(10, 40, "Player 1:");
    theScreen->drawString(160, 40, "Player 2:");

    theScreen->drawString(10, 50, "Level: ");
    std::string level = std::to_string(player1->getLevel());
    theScreen->drawString(80, 50, level);
    theScreen->drawString(160, 50, "Level: ");
    level = std::to_string(player2->getLevel());
    theScreen->drawString(230, 50, level);

    theScreen->drawString(10, 60, "Score: ");
    std::string score = std::to_string(player1->getScore());
    theScreen->drawString(80, 60, score);
    theScreen->drawString(160, 60, "Score: ");
    score = std::to_string(player2->getScore());
    theScreen->drawString(230, 60, score);
}


void GraphDisplay::setColor(int x, int y, char c) {
    if (c == '\0') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Black);
    else if (c == 'T') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Blue);
    else if (c == 'O') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Cyan);
    else if (c == 'J') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Green);
    else if (c == 'L') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Orange);
    else if (c == 'S') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Red);
    else if (c == 'Z') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Magenta);
    else if (c == 'I') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Yellow);
    else if (c == '?') theScreen->fillRectangle(x, y, 10, 10, Xwindow::White);
    else theScreen->fillRectangle(x, y, 10, 10, Xwindow::Brown);
}


void GraphDisplay::printBoard() {
    char val1;
    char val2;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            val1 = player1->getState(i, j);
            if (val1 != board1[i][j]) {
                setColor(10 + j * 10, i * 10 + 80, val1);
                board1[i][j] = val1;
            }
            val2 = player2->getState(i, j);
            if (val2 != board2[i][j]) {
                setColor(160 + j * 10, i * 10 + 80, val2);
                board2[i][j] = val2;
            }
        }
    }
}


void GraphDisplay::printNextOb(char next, int start) {
    if (next == 'O') {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) setColor(start + j * 10, i * 10 + 290, 'O');
        }
    } else if (next == 'L') {
        setColor(start + 2 * 10, 0 + 290, 'L');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10 + 290, 'L');
    } else if (next == 'T') {
        setColor(start + 1 * 10, 0 + 290, 'T');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10 + 290, 'T');
    } else if (next == 'S') {
        for (int i = 1; i < 3; i++) setColor(start + i * 10, 0 + 290, 'S');
        for (int i = 0; i < 2; i++) setColor(start + i * 10, 10 + 290, 'S');
    } else if (next == 'Z') {
        for (int i = 0; i < 2; i++) setColor(start + i * 10, 0 + 290, 'Z');
        for (int i = 1; i < 3; i++) setColor(start + i * 10, 10 + 290, 'Z');
    } else if (next == 'I') {
        for (int i = 0; i < 4; i++) setColor(start + i * 10, 0 + 290, 'I');
    } else if (next == 'J') {
        setColor(start, 0 + 290, 'J');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10 + 290, 'J');
    } else {
        setColor(start, 10 + 290, '*');
    }
}


void GraphDisplay::notify() {
    printTitle();
    printBoard();
    theScreen->drawString(10, 280, "Next:");
    theScreen->drawString(160, 280, "Next:");
    char player1Next = player1->getNext();
    char player2Next = player2->getNext();
    for (int i = 0; i < 4; i++) {
        theScreen->fillRectangle(10 + i * 10, 290, 10, 10, Xwindow::White);
        theScreen->fillRectangle(160 + i * 10, 290, 10, 10, Xwindow::White);
        theScreen->fillRectangle(10 + i * 10, 300, 10, 10, Xwindow::White);
        theScreen->fillRectangle(160 + i * 10, 300, 10, 10, Xwindow::White);
    }
    printNextOb(player1Next, 10);
    printNextOb(player2Next, 160);
}


GraphDisplay::~GraphDisplay() {
    delete theScreen;
}

void GraphDisplay::updateBoard() {
    printBoard();
}
