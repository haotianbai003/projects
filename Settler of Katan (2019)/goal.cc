#include "goal.h"

Goal::Goal(Student* owner, int pos): owner{owner}, pos{pos} {}

Student* Goal::getOwner() {
    return owner;
}

bool Goal::isAchieved() {
    if (owner == nullptr) return false;
    return true;
}

void Goal::achieveGoal(Student* s) {
    owner = s;
}

int Goal::getPos() {
    return pos;
}
