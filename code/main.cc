#include "cmdl.h"

int main(int argc, char** argv) {

    CMDL game{argv, argc};
    game.startGame();
    
}
