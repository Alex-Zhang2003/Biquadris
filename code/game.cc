#include "game.h"
#include <iostream>

Game::Game(bool textOnly, int level, std::string file1, std::string file2, int seed):
    textOnly{textOnly}, player1{level, false, file1, seed}, player2{level, false, file2, seed}, command{&player1, &player2, this}, textDisplay{&player1, &player2} {
    
    p1Dead = false;
    p2Dead = false;
    hiScore = 0;
    gameFinished = false;

    curPlayer = &player1;

    if (textOnly == false) {
        // graphicDisplay = new graphicDisplay(&player1, &player2);
    }
}

void Game::init() {

    while(!gameFinished) {
        // use try catch statement to restart the game
        runTurn();
        switchPlayer();
    }

    if (playAgain()) {
        restart();
        init();
    }
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

    while (input != "y" || input != "n") {
        std::cin >> input;
    }

    if (input == "y") {
        return true;
    }

    return false;
}

void Game::runTurn() {

    curPlayer->updateObj();

    if (!curPlayer->insert()) {
        if (curPlayer == &player1) {
            p1Dead = true;
        } else {
            p2Dead = true;
        }
        return;
    }

    while (!curPlayer->isDropped()) {
        command.readCommand();
        command.runCommand();
        curPlayer->notifyDisplay();
    }
}

void Game::restart() {

    p1Dead = false;
    p2Dead = false;
    hiScore = 0;
    gameFinished = false;

    player1 = {player1.getLevel(), false, player1.getFile(), player1.getSeed()};
    player2 = {player2.getLevel(), false, player1.getFile(), player2.getSeed()};
    curPlayer = &player1;

}





