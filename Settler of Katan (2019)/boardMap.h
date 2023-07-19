#ifndef BOARDMAP_H
#define BOARDMAP_H
#include <vector>

struct Relation {
    char type;
    int pos;
};

class BoardMap{
        std::vector<std::vector<Relation>> boardRelation;
        std::vector<int> findLoc(char locType, int goalNum) const;
    public:
        // constructs 2d vector boardRelation
        BoardMap();
        // updates result with the neighour goals of a given goal
        void getNeighGoalOfGoal(int goalNum, std::vector<int>& result) const;
        // updates result with the neighour criteria of a given goal
        void getNeighCritOfGoal(int goalNum, std::vector<int>& result) const;
        // updates result with the neighour goals of a given criterion
        void getNeighGoalOfCrit(int critNum, std::vector<int>& result) const;
        // updates result with the neighour criteria of a given criterion
        void getNeighCritOfCrit(int critNum, std::vector<int>& result) const;
};

#endif
