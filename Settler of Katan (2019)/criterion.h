// Criterion.h
#ifndef Criterion_H
#define Criterion_H
#include <vector>
class Student;

// constants (upgrade costs)
const std::vector<std::vector<int>> upgradeCosts{{1, 1, 1, 0, 1}, {0, 0, 2, 3, 0}, {3, 2, 2, 2, 1}};

class Criterion {
    private:
        Student* owner;
        int level;
        int pos;
    public:
        Criterion(Student* s = nullptr, int level = 0, int pos = 0);

        bool isAchieved();
        bool isImprovable();
        void improveCriterion(Student* s);
        int getLevel();
        void forceCriterion(Student* s, int lev);
        Student* getOwner();
        int getPos();
};

#endif
