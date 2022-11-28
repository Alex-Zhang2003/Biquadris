#include "graphdisplay.h"
#include <iostream>
#include <string>
#include <sstream>

GraphDisplay::GraphDisplay(Player *player1, Player *player2, Xwindow *theScreen, int HiScore):
    player1{player1}, player2{player2}, HiScore{HiScore} {
        theScreen = new Xwindow{280, 280};
    }


void GraphDisplay::printTitle() {
    theScreen->drawString(70, 10, "Hi Score: ");
    std::stringstream ss;
    ss << HiScore;
    std::string HiScore_String = ss.str();
    theScreen->drawString(170, 10, HiScore_String);
    theScreen->drawString(0, 40, "Player 1:");
    theScreen->drawString(150, 40, "Player 2:");

    theScreen->drawString(0, 50, "Level: ");
    int playerLevel = player1->getLevel();
    ss << playerLevel;
    std::string level = ss.str();
    theScreen->drawString(70, 50, level);
    theScreen->drawString(150, 50, "Level: ");
    playerLevel = player2->getLevel();
    ss << playerLevel;
    level = ss.str();
    theScreen->drawString(220, 50, level);

    theScreen->drawString(0, 60, "Score: ");
    int playerScore = player1->getScore();
    ss << playerScore;
    std::string score = ss.str();
    theScreen->drawString(70, 60, score);
    theScreen->drawString(150, 70, "Score: ");
    playerScore = player2->getScore();
    ss << playerScore;
    score = ss.str();
    theScreen->drawString(220, 70, score);
}


void GraphDisplay::setColor(int x, int y, char c) {
    if (c == ' ') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Black);
    else if (c == 'T') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Blue);
    else if (c == 'O') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Brown);
    else if (c == 'J') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Green);
    else if (c == 'L') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Orange);
    else if (c == 'S') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Red);
    else if (c == 'Z') theScreen->fillRectangle(x, y, 10, 10, Xwindow::White);
    else if (c == 'I') theScreen->fillRectangle(x, y, 10, 10, Xwindow::Yellow);
    else theScreen->fillRectangle(x, y, 10, 10, Xwindow::Cyan);
}


void GraphDisplay::printBoard() {
    char val1;
    char val2;
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 11; j++) {
            val1 = player1->getState(i, j);
            val2 = player2->getState(i, j);
            setColor(0 + j * 10, i * 10 + 80, val1);
            setColor(150 + j * 10, i * 10 + 80, val2);
        }
    }
}


void GraphDisplay::printNextOb(char next, int start) {
    if (val == 'O') {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) setColor(start + j * 10, i * 10, 'O');
        }
    } else if (val == 'L') {
        setColor(start + 2 * 10, 0, 'L');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10, 'L');
    } else if (val == 'T') {
        setColor(start + 1 * 10, 0, 'T');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10, 'T');
    } else if (val == 'S') {
        for (int i = 1; i < 3; i++) setColor(start + i * 10, 0, 'S');
        for (int i = 0; i < 2; i++) setColor(start + i * 10, 10, 'S');
    } else if (val == 'Z') {
        for (int i = 0; i < 2; i++) setColor(start + i * 10, 0, 'Z');
        for (int i = 1; i < 3; i++) setColor(start + i * 10, 10, 'Z');
    } else if (val == 'I') {
        for (int i = 0; i < 4; i++) setColor(start + i * 10, 0, 'I');
    } else if (val == 'J') {
        setColor(start, 0, 'J');
        for (int i = 0; i < 3; i++) setColor(start + i * 10, 10, 'J');
    } else {
        setColor(start, 10, '*');
    }
}


void GraphDisplay::notify() {
    printTitle();
    printBoard();
    theScreen->drawString(0, 280, "Next:");
    theScreen->drawString(150, 280, "Next:");
    char player1Next = player1->getNext();
    char player2Next = player2->getNext();
    printNextOb(player1Next, 0);
    printNextOb(player2Next, 150);
}


GraphDisplay::~GraphDisplay() {
    delete player1;
    delete player2;
    delete theScreen;
}


