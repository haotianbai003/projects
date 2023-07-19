#include "criterion.h"

Criterion::Criterion(Student* s, int level, int pos):
    owner{s}, level{level}, pos{pos} {}

bool Criterion::isAchieved() {
    if (owner == nullptr) return false;
    else return true;
}

bool Criterion::isImprovable() {
    if (level >= 3) return false;
    else return true;
}

void Criterion::improveCriterion(Student* s) {
    owner = s;
    level++;
}

int Criterion::getLevel() {
    return level;
}

void Criterion::forceCriterion(Student* s, int lev) {
    owner = s;
    level = lev;
}

Student* Criterion::getOwner() {
    return owner;
}

int Criterion::getPos() {
    return pos;
}


