#include "game.h"
#include <iostream>

Game::Game(bool textOnly, int level, std::string file1, std::string file2, int seed):
    player1{level, false, file1, seed}, player2{level, false, file2, seed}, command{&player1, &player2, this}, textDisplay{&player1, &player2}, textOnly{textOnly} {
    
    std::cout << "game ctor started" << std::endl;
    p1Dead = false;
    p2Dead = false;
    hiScore = 0;
    gameFinished = false;

    curPlayer = &player1;

    player1.attach(&textDisplay);
    player2.attach(&textDisplay);

    if (textOnly == false) {
        graphicDisplay = new GraphDisplay(&player1, &player2);
        player1.attach(graphicDisplay);
        player2.attach(graphicDisplay);
    } else {
        graphicDisplay = nullptr;
    }

    std::cout << "game ctor done" << std::endl;
}

Game::~Game() {
    delete graphicDisplay;
}

void Game::init() {

    std::cout<< "init game" << std::endl;
    curPlayer->notifyDisplay();
    while(!gameFinished) {
        // use try catch statement to restart the game
        runTurn();
        if (p1Dead && p2Dead) {
            break;
        }
        curPlayer->notifyDisplay();
        switchPlayer();
        std::cout << "switch turn" << std::endl;
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

    std::cout << "the current object is " << curPlayer->getCurObj() << std::endl;

    if (!curPlayer->insert()) {
        if (curPlayer == &player1) {
            std::cout << "player 1 is dead" << std::endl;
            p1Dead = true;
            return;
        } else {
            std::cout << "player 2 is dead" << std::endl;
            p2Dead = true;
            return;
        }
        return;
    }

    while (!curPlayer->isDropped()) {
        std::cout << "read Player Command" << std::endl;
        command.readCommand();
        command.runCommand();
    }

    curPlayer->notifyDisplay();
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

void Game::switchPlayer() {
    if (p1Dead == true) {
        curPlayer = &player2;
    } else if (p2Dead == true) {
        curPlayer = &player1;
    } else {
        if (curPlayer == &player1) {
            curPlayer = &player2;
        } else {
            curPlayer = &player1;
        }
    }
}





