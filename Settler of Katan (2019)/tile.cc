#include "tile.h"


Tile:: Tile(Resource resource, int position, int value, vector<Criterion*> criterion, vector<Goal*> goal, bool haveGoose):
    resource{resource}, position{position}, value{value}, criterion{criterion}, goal{goal}, haveGoose{haveGoose}{}
    
void Tile:: modifyGoose(bool b) {
        haveGoose = b;
}
    
 void Tile:: notify() {
            int i = 0;
            int n = criterion.size();
            while (i < n) {
                if(criterion[i]->isAchieved()) {
                Student *curr_student = criterion[i]->getOwner();
                int ammountGiven = criterion[i]->getLevel();
                curr_student->changeResource(this->getResource(), ammountGiven);
                }
                i += 1;
            }
 }
 
int Tile:: getPos() {
        return position;
}
 
 
 
int Tile::getVal() {
        return value;
}
 
Resource Tile:: getResource() {
    return resource;
}

bool Tile:: hasGoose() {
    return haveGoose;
}
 
vector<string> Tile:: canStealFrom() {
    vector<string> v;
    int n = criterion.size();
    int i = 0;
    while (i < n) {
        if ((criterion[i]->getOwner()!= nullptr) && ((criterion[i]->getOwner())->getStudentResourceCount() > 0)) {
            v.emplace_back((criterion[i]->getOwner())->getStudentColour());
        }
        i += 1;
    }
    return v;
} 

void Tile :: updateResource(Resource r) {
	resource = r;
}

void Tile:: updateVal(int n) {
	value = n;
}
