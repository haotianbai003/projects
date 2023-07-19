#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "resource.h"
#include "student.h"
#include "board.h"
#include "goose.h"
#include "printgame.h"
using namespace std;

class Game {
  int curTurn = 0; //0 = Blue, 1 = Red, 2 = Orange, 3 = Yellow
  bool gameLoaded = false;
  bool boardLoaded = false;
  bool gooseActive = false;
  string fileToLoad;
  vector<Student*> students;
  //unique_ptr<Board> board;
  Board* board = nullptr;
  Goose *goose = nullptr;
  PrintGame* printer = nullptr;
  //unique_ptr<PrintGame> printer;

  void saveGame(string file);

  Student* getStudent(string colour);
  bool checkWin();
  void clearGame();

  void setup();
  void play();
  void endGame();

  Resource sToRessource(string r);

 public:
  ~Game();
  void newGame();
  void loadGame(string file);
  void loadBoard(string file);
};

#endif
