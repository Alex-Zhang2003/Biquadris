#include "absplayer.h"

void ABSPlayer::notifyDisplay() {
    for (auto it : displays) {
        it->notify();
    }
}

void ABSPlayer::attach(ABSDisplay *o) {
    displays.push_back(o);
}

void ABSPlayer::detach(ABSDisplay *o) {
    for (auto it = displays.begin(); it != displays.end(); ++it) {
        if (*it == o) {
            displays.erase(it);
            break;
        }
    }
}

