#include "level.h"

Level::Level(int level): level{level} {}

Level::~Level() {}

int Level::getLevel() const {
    return level;
}

void Level::changeFile(std::string newFile) {}

void Level::noRandom(){}

void Level::setRandom(){}




