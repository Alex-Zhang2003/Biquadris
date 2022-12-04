#include "game.h"
#include <iostream>
#include <exception>

Game::Game(bool readGraphic, int level, std::string file1, std::string file2, int seed):
    readGraphic{readGraphic}, player1{level, true, file1, seed}, player2{level, true, file2, seed}, command{&player1, &player2, this}, textDisplay{&player1, &player2, this} {
    
    hiScore = 0;

    curPlayer = &player1;

    player1.attach(&textDisplay);
    player2.attach(&textDisplay);

    if (readGraphic) {
        graphicDisplay = new GraphDisplay(&player1, &player2, this);
        player1.attach(graphicDisplay);
        player2.attach(graphicDisplay);
    } else {
        graphicDisplay = nullptr;
    }

}

Game::~Game() {
    delete graphicDisplay;
}

std::string Game::init() {
    curPlayer->notifyDisplay();
    while(true) {
        try {
            runTurn();
        } catch (std::string exp) {
            return exp;
        }
        if (player1.isDead() && player2.isDead()) {
            break;
        }
        switchPlayer();
        std::cout << "SWITCH TURN" << std::endl;
    }
    if (playAgain()) {
        return "Game Restarted";
    }
    return "";
}

bool Game::playAgain() {

    std::string winner = "0";
    if (player1.getScore() > player2.getScore()) {
        winner = "1";
    } else if (player1.getScore() < player2.getScore()) {
        winner = "2";
    }
    
    if (winner == "0") {
        std::cout << "It's a tie, would you like to play again (y/n)" << std::endl;
    } else {
        std::cout << "The winner is player " + winner + " , " + "would you like to play again (y/n)" << std::endl;
    }

    std::string input = "";

    while (input != "y" && input != "n") {
        std::cin >> input;
    }

    if (input == "y") {
        return true;
    }

    return false;
}

void Game::runTurn() {

    if (curPlayer == &player1) {
        std::cout<< "it is player1's turn" << std::endl;
    } else {
        std::cout<< "it is player2's turn" << std::endl;
    }

    curPlayer->updateObj();
    curPlayer->insert();
    
    if (curPlayer->isDead()) {
        if (curPlayer->canRevive()) {
            if (!revivePlayer()) {
                return;
            }
        } else {
            return;
        }
    }

    while (!curPlayer->isDropped()) {
        curPlayer->notifyBoard();
        std::cout << "read Player Command" << std::endl;
        command.readCommand();
        command.runCommand();
    }
    
    int rowsCleared = curPlayer->update();
    if (rowsCleared >= 2) {
        command.specialAction();
    }
    if (curPlayer->getScore() > hiScore) {
        hiScore = curPlayer->getScore();
    }

    curPlayer->notifyDisplay();
}

void Game::switchPlayer() {
    if (player1.isDead() || curPlayer == &player1) {
        curPlayer = &player2;
        command.switchPlayer(&player2);
    } else if (player2.isDead() || curPlayer == &player2){
        curPlayer = &player1;
        command.switchPlayer(&player1);
    }
}

int Game::getHiScore() {
    return hiScore;
}
void Game::setHiScore(int score) {
    hiScore = score;
}

bool Game::revivePlayer() {

    std::cout << "You are dead. However, you could be REVIVED if you sacrifice half your points to the all mighty Professor LUSHMAN" << std::endl;
    std::cout << "The blocks currently on screen will not worth any points, and only new blocks dropped can earn points. BE CAREFUL WHAT YOU WISH FOR!" << std::endl;
    std::cout << "enter y/n" << std::endl;
    std::string input;
    while (input != "y" && input != "n") {
        std::cin >> input;
    }
    if (input == "y") {
        curPlayer->doRevive();
        return true;
    } else {
        return false;
    }
}


 