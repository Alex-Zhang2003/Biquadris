#include "absplayer.h"
#include "absdisplay.h"

void ABSPlayer::notifyDisplay() {
    for (auto it : displays) {
        it->notify();
    }
}

void ABSPlayer::attach(std::shared_ptr<ABSDisplay> o) {
    displays.push_back(o);
}

void ABSPlayer::detach(std::shared_ptr<ABSDisplay> o) {
    for (auto it = displays.begin(); it != displays.end(); ++it) {
        if (*it == o) {
            displays.erase(it);
            break;
        }
    }
}

void ABSPlayer::notifyBoard() {
    for (auto it : displays) {
        it->updateBoard();
    }
}



