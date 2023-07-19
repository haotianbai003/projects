#include <string>
#include "game.h"
#include "boardMap.h"
using namespace std;

const BoardMap BM;

int main(int argc, char *argv[]) {
  Game g;
  bool loaded = false;
  bool board = false;
  string file;

  for (int i = 1; i < argc; ++i) {
    if (string(argv[i]) == "-seed") {
      int s = stoi(argv[++i]);
      srand(s);
    }
    if (string(argv[i]) == "-load") {
      file = argv[++i];
      loaded = true;
    }
    if (string(argv[i]) == "-board") {
      file = argv[++i];
      board = true;
    }
  }

  if (loaded) {
    g.loadGame(file);
  } else if (board) {
    g.loadBoard(file);
  } else {
    g.newGame();
  }

}

