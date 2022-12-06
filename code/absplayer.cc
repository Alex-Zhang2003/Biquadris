#include "absplayer.h"
#include "absdisplay.h"

void ABSPlayer::notifyDisplay() {
    for (std::unique_ptr<ABSDisplay> it : displays) {
        it->notify();
    }
}

void ABSPlayer::attach(std::unique_ptr<ABSDisplay> o) {
    displays.push_back(o);
}

void ABSPlayer::detach(std::unique_ptr<ABSDisplay> o) {
    for (auto it = displays.begin(); it != displays.end(); ++it) {
        if (*it == o) {
            displays.erase(it);
            break;
        }
    }
}

void ABSPlayer::notifyBoard() {
}



