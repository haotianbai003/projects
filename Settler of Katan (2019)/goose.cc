#include "goose.h"

void Goose::moveGoose(Tile *t) {
    t->modifyGoose(true);
    if(pos != nullptr) {
    pos->modifyGoose(false);
    }
    pos = t;
}


void Goose:: halveResource(ostream& out, vector<Student*>& vs) {
    int i = 0;
    int n = vs.size();
    while (i < n) {
        if (vs[i]->getStudentResourceCount() >= 10) { // this to get the total number of resources
            int loss = vs[i]->getStudentResourceCount() / 2;
            int j = 1;
            int num_tut_lost = 0;
            int num_stud_lost = 0;
            int num_caf_lost = 0;
            int num_lab_lost = 0;
            int num_lec_lost = 0;
            while (j <= loss) {
               Resource r = vs[i]->rndSelect();
               if (r == TUTORIAL) {
                   num_tut_lost += 1;
               } else if (r == STUDY) {
                   num_stud_lost += 1;
               } else if (r == CAFFEINE) {
                   num_caf_lost += 1;
               } else if (r == LAB) {
                   num_lab_lost += 1;
               } else if (r == LECTURE) {
                   num_lec_lost += 1;
               }
               j += 1;
            }
            out << "Student " << vs[i]->getStudentColour() << " loses "<<loss << " to the geese. They lose:"<< endl; // gets colour
            if (num_tut_lost > 0) {
                out << num_tut_lost<< " TUTORIAL";
            }
            if (num_stud_lost > 0) {
                out << num_stud_lost<< " STUDY";
            }
            if (num_caf_lost > 0) {
                out << num_caf_lost<< " CAFFEINE";
            }
            if (num_lab_lost > 0) {
                out << num_lab_lost<< " LAB";
            }
            if (num_lec_lost > 0) {
                out << num_lec_lost<< " LECTURE";
            }
        }
        i += 1;
    }
}


Resource Goose::steal(Student *s1, Student *s2) {
    Resource r = s2->rndSelect();
    s1->changeResource(r, 1); // 
    return r;
}


Tile *Goose::getCurrTile() {
    return pos;
}


vector<string> Goose:: canSteal() {
    Tile *t = getCurrTile();
    return t->canStealFrom();
}

int Goose::getTileNum() {
	return pos->getPos();
}
