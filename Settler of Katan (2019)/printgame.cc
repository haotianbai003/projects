#include "printgame.h"
using namespace std;

void PrintGame::printBoard(Board *b) {
  //cout << b;
  //For now we'll just use printBoard();
  b->printBoard(cout);
}

void PrintGame::printStatus(Student *s) {
  string status = s->getStudentColour();
  status += " has ";
  int cc = s->getStudentCriteria().size()/2;
  status += to_string(cc) + " course criteria, ";
  int i = 0;
  for (auto &r : s->getStudentResource()) {
    status += to_string(r);
    if (i == 0) status += " caffeines, ";
    if (i == 1) status += " labs, ";
    if (i == 2) status += " lectures, ";
    if (i == 3) status += " studies, ";
    if (i == 4) status += " tutorials.";
    ++i;
  }
  cout << status << endl;
}

