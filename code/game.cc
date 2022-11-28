#include "game.h"

Game::Game(bool textOnly, int level, std::string file1, std::string file2, int seed = 1):
    textOnly{textOnly} {
    
    p1Dead = false;
    p2Dead = false;
    hiScore = 0;
    gameFinished = false;
    turnFinished = false;

    player1 = (level, false, file1, seed);
    player2 = (level, false, file2, seed);

    command = (&player1, &player2);

    textDisplay = (&player1, &player2);

    if (textOnly == false) {
        graphicDisplay = (&player1, &player2);
    }
}






