#include "textdisplay.h"
#include <iostream>
#include <string>
#include "game.h"

TextDisplay::TextDisplay(Player *player1, Player *player2, Game* game):
    game{game}, player1{player1}, player2{player2},
    next {std::make_unique< std::unique_ptr<char[]>[] >(2)} { 
    for (int i = 0; i < 2; i++) {
        std::unique_ptr<char[]> rows = std::make_unique<char[]>(28);
        for (int j = 0; j < 28; j++) {
            rows[j] = ' ';
        }
        next[i] = std::move(rows);
    }
}

void TextDisplay::printTitle() {
    std::cout << "        Hi Score: " << game->getHiScore() << "      " << std::endl;
    std::cout << std::endl;
    std::cout << "Player 1:         Player 2:" << std::endl;
    std::cout << "Level: " << player1->getLevel() << "          " << "Level: " << player2->getLevel() << std::endl;
    int player1Score = player1->getScore();
    std::cout << "Score: " << player1Score;
    std::string score = std::to_string(player1Score);
    int lengthLeft = 20 - 9 - score.length();
    for (int i = 0; i < lengthLeft; i++) std::cout << " ";
    std::cout << "Score: " << player2->getScore() << std::endl;
}


void TextDisplay::printBoard() {
    std::cout << "+";
    for (int i = 0; i < 11; i++) std::cout << "-";
    std::cout << "+";
    std::cout << "     ";
    
    std::cout << "+";
    for (int i = 0; i < 11; i++) std::cout << "-";
    std::cout << "+" << std::endl;
    
    for (int i = 0; i < 18; i++) {
        std::cout << "|";
        for (int j = 0; j < 11; j++) {
            char c = player1->getState(i, j);
            if (c != '\0') std::cout << c;
            else std::cout << ' ';
        }
        std::cout << "|     ";
        
        std::cout << "|";
        for (int j = 0; j < 11; j++) {
            char c = player2->getState(i, j);
            if (c != '\0') std::cout << c;
            else std::cout << ' ';
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "+";
    for (int i = 0; i < 11; i++) std::cout << "-";
    std::cout << "+";
    std::cout << "     ";
    
    std::cout << "+";
    for (int i = 0; i < 11; i++) std::cout << "-";
    std::cout << "+";
    std::cout << std::endl;
    std::cout << std::endl;
}


void TextDisplay::setNextOb(char val, int start) {
    if (val == 'O') {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) next[i][start + j] = 'O';
        }
    } else if (val == 'L') {
        next[0][start + 2] = 'L';
        for (int i = 0; i < 3; i++) next[1][start + i] = 'L';
    } else if (val == 'T') {
        next[0][start + 1] = 'T';
        for (int i = 0; i < 3; i++) next[1][start + i] = 'T';
    } else if (val == 'S') {
        for (int i = 1; i < 3; i++) next[0][start + i] = 'S';
        for (int i = 0; i < 2; i++) next[1][start + i] = 'S';
    } else if (val == 'Z') {
        for (int i = 0; i < 2; i++) next[0][start + i] = 'Z';
        for (int i = 1; i < 3; i++) next[1][start + i] = 'Z';
    } else if (val == 'I') {
        for (int i = 0; i < 4; i++) next[0][start + i] = 'I';
    } else if (val == 'J') {
        next[0][start] = 'J';
        for (int i = 0; i < 3; i++) next[1][start + i] = 'J';
    } else {
        next[0][start] = '*';
    }
}


void TextDisplay::printNextOb() {
    std::cout << "Next:             Next:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 28; j++) std::cout << next[i][j];
        if (i == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}


void TextDisplay::notify() {
    printTitle();
    printBoard();
    char player1Next = player1->getNext();
    char player2Next = player2->getNext();
    setNextOb(player1Next, 0);
    setNextOb(player2Next, 18);
    printNextOb();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 28; j++) next[i][j] = ' ';
    }
}


TextDisplay::~TextDisplay() {}

void TextDisplay::updateBoard() {}



