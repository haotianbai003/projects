#ifndef TILE_H
#define TILE_H

#include <vector>
#include <string>
#include "resource.h"
#include "goal.h"
#include "criterion.h"
#include "student.h"

using namespace std;

class Tile{
    Resource resource;
    int position;
    int value;
    vector<Criterion*> criterion;
    vector<Goal*> goal;
    bool haveGoose;
    
    public:
    Tile(Resource resource, int position, int value, vector<Criterion*> criterion, vector<Goal*> goal, bool haveGoose);
    void modifyGoose(bool b);
    void notify();
    int getPos();
    int getVal();
    Resource getResource();
    bool hasGoose();
    vector<string> canStealFrom();
    void updateResource(Resource r);
    void updateVal(int n);
};

#endif
