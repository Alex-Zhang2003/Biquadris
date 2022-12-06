#include "graphdisplay.h"
#include <iostream>
#include <string>
#include "game.h"

GraphDisplay::GraphDisplay(Player *player1, Player *player2, Game* game):
    game{game}, player1{player1}, player2{player2}, theScreen{std::make_unique<Xwindow>(300, 400)}, 
    board1 {std::make_unique< std::unique_ptr<char[]>[] >(18)},
    board2 {std::make_unique< std::unique_ptr<char[]>[] >(18)},
    scoreUpdated{true}, score1{-1}, score2{-1}, level1{-1}, level2{-1}, hiScore{0} {
    for (int i = 0; i < 18; i++) {
        std::unique_ptr<char[]> rows1 = std::make_unique<char[]>(11);
        std::unique_ptr<char[]> rows2 = std::make_unique<char[]>(11);
        for (int j = 0; j < 11; j++) {
            rows1[j] = ' ';
            rows2[j] = ' ';
        }
    board1[i] = std::move(rows1);
    board2[i] = std::move(rows2);
    }
}


void GraphDisplay::printTitle() {
    theScreen->drawString(80, 10, "Hi Score: ");
    std::string HiScore_String = std::to_string(game->getHiScore());
    if (hiScore != game->getHiScore()) {
        theScreen->fillRectangle(180, 0, 80, 10, Xwindow::White);
        theScreen->drawString(180, 10, HiScore_String);
        hiScore = game->getHiScore();
    }
    theScreen->drawString(10, 40, "Player 1:");
    theScreen->drawString(160, 40, "Player 2:");

    theScreen->drawString(10, 50, "Level: ");
    std::string level;
    if (level1 != player1->getLevel()) {
        theScreen->fillRectangle(80, 40, 80, 10, Xwindow::White);
        level = std::to_string(player1->getLevel());
        theScreen->drawString(80, 50, level);
        level1 = player1->getLevel();
    }
    theScreen->drawString(160, 50, "Level: ");
    if (level2 != player2->getLevel()) {
        theScreen->fillRectangle(230, 40, 80, 10, Xwindow::White);
        level = std::to_string(player2->getLevel());
        theScreen->drawString(230, 50, level);
        level2 = player2->getLevel();
    }

    theScreen->drawString(10, 60, "Score: ");
    std::string score;
    if (score1 != player1->getScore()) {
        theScreen->fillRectangle(80, 50, 80, 10, Xwindow::White);

        score = std::to_string(player1->getScore());
        theScreen->drawString(80, 60, score);
        score1 = player1->getScore();
    }
    theScreen->drawString(160, 60, "Score: ");
    if (score2 != player2->getScore()) {
        theScreen->fillRectangle(230, 50, 80, 10, Xwindow::White);
        score = std::to_string(player2->getScore());
        theScreen->drawString(230, 60, score);
        score2 = player2->getScore();
    }
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


GraphDisplay::~GraphDisplay() {}

void GraphDisplay::updateBoard() {
    printBoard();
}


