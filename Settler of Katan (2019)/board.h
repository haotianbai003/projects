#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <string>
#include <random>
#include "resource.h"
#include "criterion.h"
#include "tile.h"
#include "goal.h"
#include "student.h"
#include "boardMap.h"
#include "sstream"

using namespace std;

class Board {
  vector<Tile*> tiles;
  vector<Criterion*> criterion;
  vector<Goal*> goal;
  Resource roll_resource(int *tut, int *stud, int *caf, int *lab, int *lec, int *net);
  int roll_value (int *two, int *twelve, int *three, int *four, int *five, int *six, int *eight, int *nine, int *ten, int *eleven);
public:
Board();
  ~Board();
  string saveBoard();
  void loadStringBoard(string s);
  Tile *getTile(int n);
  bool checkCriterion(int n);
  bool checkGoal(int n);
  int buildGoal(int n, Student *s);
  int buildCriterion(int n, bool is_improve, bool useResources, Student *s);
  void printBoard(ostream &out);
  void giveResources(int n);
  void loadGoal(int pos, Student *s);
  void loadCriterion(int pos, int completion, Student *s);
};

#endif
