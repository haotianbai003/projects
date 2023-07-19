// student.cc
#include "student.h"
#include "boardMap.h"

// ctor
Student::Student(char colour): colour{colour}, 
    resource{std::vector<int>(5, 0)}, goal{}, criterion{}, dice{Dice{}} {}

// remove giveAmt instance of resource give, increase takeAmt
//     instance of take in current student; does the opposite in *s
bool Student::trade(Resource give, Resource take, Student* s, 
    int giveAmt, int takeAmt) {
    // try to trade
    this->changeResource(give, -1 * giveAmt);
    s->changeResource(give, giveAmt);
    this->changeResource(take, takeAmt);
    s->changeResource(take, -1 * takeAmt);
    // check if trade was successful (no negatives)
    bool succ = true;
    std::vector<int> sRes = s->getStudentResource();
    for (int i = 0; i < resourceType.size(); ++i) {
        if (sRes.at(i) < 0 || resource.at(i) < 0) {
            succ = false;
        }
    }
    if (! succ) {
        this->changeResource(give, giveAmt);
        s->changeResource(give, -1 * giveAmt);
        this->changeResource(take, -1 * takeAmt);
        s->changeResource(take, takeAmt);
        return false;
    }
    return true;
}

// updates the dice to either currDiceLoaded = true or currDiceLoaded = false
void Student::updateDice(bool b) {
    dice.setLoaded(b);
}

int Student::rollDice() {
    return dice.roll();
}

// will attempt to improve Criterion at *c, if i own this and has the resources
int Student::improveCriterion(Criterion* c) {
    // determine if i own this
    if (c->getOwner() != this) {
        return -1;
    }
    // check if upgradable
    if (! c->isImprovable()) {
        return -1;
    }
    // get upgrade cost
    int lev = c->getLevel();
    std::vector<int> cost;
    cost = upgradeCosts.at(lev);
    // compare cost to resource and check if possible
    for (int i = 0; i < cost.size(); ++i) {
        if (cost.at(i) > resource.at(i)) {
            return 0; // return false if not enough resources
        }
    }
    // otherwise, use the resources
    for (int i = 0; i < cost.size(); ++i) {
        resource.at(i) -= cost.at(i);
    }
    // upgrade
    c->improveCriterion(this);
    return 1;
}

// attempt to complete crit *c, if i have the goals and resources
int Student::completeCriterion(Criterion* c) {
    // determine if i have a goal leading to it
    bool canBuild = false;
    std::vector<int> neigbours;
    BM.getNeighGoalOfCrit(c->getPos(), neigbours);
    for (int i = 0; i < goal.size(); ++i) {
        for (int j = 0; j < neigbours.size(); ++j) {
            if (goal.at(i)->getPos() == neigbours.at(j)) {
                canBuild = true;
            }
        }
    }
    if (! canBuild) {
        return -1;
    }
    // get upgrade cost
    std::vector<int> cost = upgradeCosts.at(0);
    // compare cost to resource and check if possible
    for (int i = 0; i < cost.size(); ++i) {
        if (cost.at(i) > resource.at(i)) {
            return 0; // return false if not enough resources
        }
    }
    // otherwise, complete the criteron
    criterion.emplace_back(c);
    // and use the resources
    for (int i = 0; i < cost.size(); ++i) {
        resource.at(i) -= cost.at(i);
    }
    // complete the criterion
    c->forceCriterion(this, 1);
    return 1;
}

// forcefully add a criterion *c at level to student
void Student::addCriterion(Criterion* c, int level) {
    criterion.emplace_back(c);
    c->forceCriterion(this, level);
}

// forcefully add a goal *g at level to student
void Student::addGoal(Goal* g) {
    goal.emplace_back(g);
    g->achieveGoal(this);
}

// attempt to achieve Goal *g, if have the neighbours and resources
int Student::achieveGoal(Goal* g) {
    bool canBuild = false;
    // if student has neigbouring goals
    std::vector<int> neigbours;
    BM.getNeighGoalOfGoal(g->getPos(), neigbours);
    for (int i = 0; i < goal.size(); ++i) {
        for (int j = 0; j < neigbours.size(); ++j) {
            if (goal.at(i)->getPos() == neigbours.at(j)) {
                canBuild = true;
            }
        }
    }
    neigbours.clear();
    // if student has neighbouring criterion
    BM.getNeighCritOfGoal(g->getPos(), neigbours);
    for (int i = 0; i < criterion.size(); ++i) {
        for (int j = 0; j < neigbours.size(); ++j) {
            if (criterion.at(i)->getPos() == neigbours.at(j)) {
                canBuild = true;
            }
        }
    }
    if (! canBuild) {
        return -1;
    }
    // check if I have the resources
    if (resource.at(3) >= 1 && resource.at(4) >= 1) {
        --resource.at(3);
        --resource.at(4);
        g->achieveGoal(this);
        goal.emplace_back(g);
        return 1;
    }
    return 0;
}

// returns how much resources (int) the student has
int Student::getStudentResourceCount() {
    int total = 0;
    for (int i : resource) {
        total += i;
    }
    return total;
}

// will change current student's Resource r by 'amount'
void Student::changeResource(Resource r, int amount) {// amount can be +/-
    switch (r)
    {
        case CAFFEINE:
            resource.at(0) += amount;
            break;
        case LAB:
            resource.at(1) += amount;
            break;
        case LECTURE:
            resource.at(2) += amount;
            break;
        case STUDY:
            resource.at(3) += amount;
            break;
        case TUTORIAL:
            resource.at(4) += amount;
            break;
        default:
            break;
    }
}

// randomly select a resource from student, removes and returns it
Resource Student::rndSelect() {
    int total = 0, take = 0;
    total = this->getStudentResourceCount();
    take = rand() % (total - 1);

    for (int pos = 0; pos < resource.size(); ++pos) {
        if (resource.at(pos) >= take) {
            changeResource(resourceType.at(pos), -1);
            return resourceType.at(pos);
        }
        else {
            take -= resource.at(pos);
        }
    }
    return NETFLIX;
}

// return student's colour as str
std::string Student::getStudentColour() {
    switch (colour)
    {
        case 'B':
            return "Blue";
            break;
        case 'R':
            return "Red";
            break;
        case 'O':
            return "Orange";
            break;
        case 'Y':
            return "Yellow";
            break;
        default:
            return "Unknown";
            break;
    }
}

// return student's colour as a char e.g.: 'C'
char Student::getStudentChar() {
    return colour;
}

// return student's resources in order of:
//     CAFFEINE, LAB, LECTURE, STUDY, TUTORIAL
std::vector<int> Student::getStudentResource() {
    return resource;
}

// return student's completed goals positions
std::vector<int> Student::getStudentGoals() {
    std::vector<int> g;
    for (auto &p : goal) {
        g.emplace_back(p->getPos());
    }
    return g;
}

// return student's completed criteria positions followed by level
std::vector<int> Student::getStudentCriteria() {
    std::vector<int> c;
    for (auto &p : criterion) {
        c.emplace_back(p->getPos());
        c.emplace_back(p->getLevel());
    }
    return c;
}
