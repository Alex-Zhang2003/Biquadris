#include "level.h"

Level::Level(int level): level{level}, cur{'\0'} {}

Level::~Level() {}

int Level::getLevel() const {
    return level;
}

char Level::getCur() const {
    return cur;

}


