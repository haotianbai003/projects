#include "boardMap.h"

BoardMap::BoardMap() {
    int numCrit = 0, numGoal = 0;

    // Row 0
    std::vector<Relation> temp{Relation{' ', -1}, Relation{' ', -1}, 
        Relation{' ', -1}, Relation{' ', -1}, Relation{'x', numCrit++}, 
        Relation{'-', numGoal++}, Relation{'x', numCrit++}, Relation{' ', -1},
        Relation{' ', -1}, Relation{' ', -1}, Relation{' ', -1}};

    boardRelation.emplace_back(temp);
    temp.clear();

    // Row 1
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{'-', numGoal++});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{'-', numGoal++});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});

    boardRelation.emplace_back(temp);
    temp.clear();

    // Row 2
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 

    boardRelation.emplace_back(temp);
    temp.clear();

    // Row 3
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1});

    boardRelation.emplace_back(temp);
    temp.clear();

    // Row 4 to 10
    for (int i = 0; i < 13; ++i) {
        if (i % 4 == 0) {
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{'x', numCrit++});
            
            boardRelation.emplace_back(temp);
            temp.clear();
        }
        else if (i % 2 == 0) {
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{'x', numCrit++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'x', numCrit++});

            boardRelation.emplace_back(temp);
            temp.clear();
        }
        else {
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'-', numGoal++}); 
            temp.emplace_back(Relation{' ', -1}); 
            temp.emplace_back(Relation{'-', numGoal++});

            boardRelation.emplace_back(temp);
            temp.clear();
        }
    }

    // 4th last
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1});

    boardRelation.emplace_back(temp);
    temp.clear();

    // 3rd last
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 

    boardRelation.emplace_back(temp);
    temp.clear();

    // 2nd last
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{'-', numGoal++});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{'-', numGoal++});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});
    temp.emplace_back(Relation{' ', -1});

    boardRelation.emplace_back(temp);
    temp.clear();

    // Last row
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{'-', numGoal++}); 
    temp.emplace_back(Relation{'x', numCrit++}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1}); 
    temp.emplace_back(Relation{' ', -1});

    boardRelation.emplace_back(temp);
    temp.clear();
}


void BoardMap::getNeighGoalOfGoal(int goalNum, std::vector<int>& result) const {
    // find the pos of goalNum
    std::vector<int> loc = findLoc('-', goalNum);
    int neighPos = 0;
    // check left up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 1).at(loc.at(1) - 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check right up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 1).at(loc.at(1) + 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check left down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 1).at(loc.at(1) - 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check right down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 1).at(loc.at(1) + 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check 2 up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 2).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check 2 down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 2).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
}


void BoardMap::getNeighCritOfGoal(int goalNum, std::vector<int>& result) const {
    // find the pos of goalNum
    std::vector<int> loc = findLoc('-', goalNum);
    int neighPos = 0;
    // check left
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) - 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check right
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) + 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 1).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 1).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
}


void BoardMap::getNeighGoalOfCrit(int critNum, std::vector<int>& result) const {
    // find the pos of goalNum
    std::vector<int> loc = findLoc('x', critNum);
    int neighPos = 0;
    // check left
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) - 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check right
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) + 1)).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 1).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 1).at(loc.at(1))).pos;
        if (neighPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
}

void BoardMap::getNeighCritOfCrit(int critNum, std::vector<int>& result) const {
    // find the pos of goalNum
    std::vector<int> loc = findLoc('x', critNum);
    int neighPos = 0;
    int nextPos = 0;
    // check 2 left
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) - 2)).pos;
        nextPos = (boardRelation.at(loc.at(0)).at(loc.at(1) - 1)).pos;
        if (neighPos != -1 && nextPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check 2 right
    try {
        neighPos = (boardRelation.at(loc.at(0)).at(loc.at(1) + 2)).pos;
        nextPos = (boardRelation.at(loc.at(0)).at(loc.at(1) + 1)).pos;
        if (neighPos != -1 && nextPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check 2 up
    try {
        neighPos = (boardRelation.at(loc.at(0) - 2).at(loc.at(1))).pos;
        nextPos = (boardRelation.at(loc.at(0) - 1).at(loc.at(1))).pos;
        if (neighPos != -1 && nextPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
    // check 2 down
    try {
        neighPos = (boardRelation.at(loc.at(0) + 2).at(loc.at(1))).pos;
        nextPos = (boardRelation.at(loc.at(0) + 1).at(loc.at(1))).pos;
        if (neighPos != -1 && nextPos != -1) {
            result.emplace_back(neighPos);
        }
    } catch(...) {}
}

std::vector<int> BoardMap::findLoc(char locType, int posNum) const {
    std::vector<int> loc;
    for (int i = 0; i < boardRelation.size(); ++i) {
        for (int j = 0; j < boardRelation.at(i).size(); ++j) {
            if (boardRelation.at(i).at(j).type == locType && 
                boardRelation.at(i).at(j).pos == posNum) {
                loc.emplace_back(i);
                loc.emplace_back(j);
                return loc;
            }
        }
    }
    // otherwise:
    loc.emplace_back(-1);
    loc.emplace_back(-1);
    return loc;
}

