#ifndef GOOSE_H
#define GOOSE_H

#include <iostream>
#include <vector>
#include <string>
#include "resource.h"
#include "student.h"
#include "tile.h"

using namespace std;

class Goose {
    Tile *pos;
    public:
    void moveGoose(Tile *t);
    void halveResource(ostream& out, vector<Student*>& vs);
    Resource steal(Student *s1, Student *s2);
    Tile *getCurrTile();
    int getTileNum();
    vector<string> canSteal();
};

#endif

