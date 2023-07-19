#ifndef PG_H
#define PG_H
#include <string>
#include <iostream>
#include "board.h"
#include "student.h"

using namespace std;

class PrintGame {
  //Game *game = nullptr;
 public:
  //~PrintGame();
  void printBoard(Board *b);
  void printStatus(Student *s);
};

#endif

