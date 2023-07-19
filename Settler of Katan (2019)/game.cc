#include "game.h"
using namespace std;


void Game::clearGame() {
  for (auto &s: students) {
      delete s;
  }
  delete goose;
  delete board;
  delete printer;
}


Game::~Game() {
  clearGame();
}


void Game::newGame() {
  clearGame();
  students.emplace_back(new Student('B'));
  students.emplace_back(new Student('R'));
  students.emplace_back(new Student('O'));
  students.emplace_back(new Student('Y'));
  goose = new Goose();
  //auto board = make_unique<Board>();
  //auto printer = make_unique<PrintGame>();
  board = new Board();
  printer = new PrintGame();
  setup();
}



void Game::loadGame(string file) {
  clearGame();
  gameLoaded = true;
  fileToLoad = file;
  board = new Board();
  students.emplace_back(new Student('B'));
  students.emplace_back(new Student('R'));
  students.emplace_back(new Student('O'));
  students.emplace_back(new Student('Y'));
  ifstream f (file);
  string line;
  getline(f, line);
  curTurn = stoi(line)%4;
  for (auto &s: students) {
    getline(f, line);
    int pos;
    istringstream ss (line);
    ss >> pos;
    s->changeResource(Resource::CAFFEINE, pos);
    ss >> pos;
    s->changeResource(Resource::LAB, pos);
    ss >> pos;
    s->changeResource(Resource::LECTURE, pos);
    ss >> pos;
    s->changeResource(Resource::STUDY, pos);
    ss >> pos;
    s->changeResource(Resource::TUTORIAL, pos);
    string goals;
    ss >> goals;
    while (ss >> pos) {
      board->loadGoal(pos, s);
    }
    ss.clear();
    string criteria;
    ss >> criteria;
    int completion;
    while (ss >> pos) {
      ss >> completion;
      board->loadCriterion(pos, completion, s);
    }
    ss.clear();
  }
  getline(f, line);
  board->loadStringBoard(line);
  goose = new Goose();
  if (getline(f, line)) {
    goose->moveGoose(board->getTile(stoi(line)));
  }
  //printer = make_unique<PrintGame>();
  printer = new PrintGame();
  f.close();
  play();
}



void Game::loadBoard(string file) {
  clearGame();
  boardLoaded = true;
  fileToLoad = file;
  ifstream f (file);
  string line;
  getline(f, line);
  students.emplace_back(new Student('B'));
  students.emplace_back(new Student('R'));
  students.emplace_back(new Student('O'));
  students.emplace_back(new Student('Y'));
  goose = new Goose();
  //board = make_unique<Board>;
  board = new Board();
  board->loadStringBoard(line);
  //printer = make_unique<PrintGame>();
  printer = new PrintGame();
  f.close();
  setup();
}



void Game::saveGame(string file) {
  ofstream f (file);
  f << curTurn << endl;
  for (auto &s : students) {
    for (auto &r : s->getStudentResource()) {
      f << r << " ";
    }
    f << "g ";
    for (auto &g : s->getStudentGoals()) {
      f << g << " ";
    }
    f << "c ";
    for (auto &c : s->getStudentCriteria()) {
      f << c << " ";
    }
    f << endl;
  }
  f << board->saveBoard() << endl;
  if (gooseActive) f << goose->getTileNum() << endl;
  f.close();
}



bool Game::checkWin() {
  //We'll make it simple, if you completed an assignment you completed the course
  for (auto &s: students) {
    int completed = s->getStudentCriteria().size()/2;
    if (completed >= 10) return true;
  }
  return false;
}



Student* Game::getStudent(string colour) {
  if ((colour == "Blue") || (colour == "blue")) return students.at(0);
  if ((colour == "Red") || (colour == "red")) return students.at(1);
  if ((colour == "Orange") || (colour == "orange")) return students.at(2);
  if ((colour == "Yellow") || (colour == "yellow")) return students.at(3);
  return students.at(3);
}



void Game::setup() {
  bool reverse = false;
  bool once = false;
  //try {
    while (curTurn >= 0) {
      cout << "Student "+ students.at(curTurn)->getStudentColour() +", where do you want to complete an Assignment?" << endl;
      int i;
      cout << ">";
      cin >> i;
      if (cin.eof()) break;
      int result = board->buildCriterion(i, false, false, students.at(curTurn));
      if (result == 1) {
        if (reverse) {
          if (!once) {
            ++curTurn;
            once = true;
          }
          --curTurn;
        } else {
          ++curTurn;
          if (curTurn == 3) reverse = true;
        }
      } else {
        cout << "You cannot build here." << endl;
      }
    }
    ++curTurn;
    if (!cin.eof()) {
      printer->printBoard(board);
      play();
    }
  //} catch (...) { cout << "io error" << endl;}
}


Resource Game::sToRessource(string r) {
  if ((r == "Caffeine") || (r == "caffeine")) return Resource::CAFFEINE;
  if ((r == "Lab") || (r == "lab")) return Resource::LAB;
  if ((r == "Lecture") || (r == "lecture")) return Resource::LECTURE;
  if ((r == "Tutorial") || (r == "tutorial")) return Resource::TUTORIAL;
  if ((r == "Study") || (r == "study")) return Resource::STUDY;
  return Resource::NETFLIX;
}


void Game::play() {
//  try {
    string cmd;
    while (true) {
      cout << "Student "+ students.at(curTurn)->getStudentColour() +"'s turn." << endl;
      printer->printStatus(students.at(curTurn));
      /* - - - - - - - - - - - - - - - - - Dice Roll - - - - - - - - - - - - - - - - - - - - */
      while (true) {
        cout << ">";
        cin >> cmd;
        if (cin.eof()) {
          break;
        } else if (cmd == "load") {
          students.at(curTurn)->updateDice(true);
        } else if (cmd == "fair") {
          students.at(curTurn)->updateDice(false);
        } else if (cmd == "roll") {
          int roll = students.at(curTurn)->rollDice();
          cout << "You rolled: " << roll << endl;
          if (roll == 7) {
            /* - - - - - - - - - - - Goose time!!! - - - - - - - - - - - */
            if (gooseActive) {
              goose->halveResource(cout, students);
            }
            cout << "Choose where to place the GEESE." << endl;
            int tile;
            cout << ">";
            cin >> tile;
            goose->moveGoose(board->getTile(tile));
            gooseActive = true;
            bool blue = false;
            bool red = false;
            bool orange = false;
            bool yellow = false;
            for (auto &sColour : goose->canSteal()) {
              if (sColour != students.at(curTurn)->getStudentColour()) {
                if (sColour == "Blue") blue = true;
                if (sColour == "Red") red = true;
                if (sColour == "Orange") orange = true;
                if (sColour == "Yellow") yellow = true;
              }
            }
            vector<string> canStealFrom;
            if (blue) canStealFrom.emplace_back("Blue");
            if (red) canStealFrom.emplace_back("Red");
            if (orange) canStealFrom.emplace_back("Orange");
            if (yellow) canStealFrom.emplace_back("Yellow");
            if (canStealFrom.size() > 0) {
              cout << "Student " << students.at(curTurn)->getStudentColour() << " can choose to steal from ";
              int i = 0;
              for (auto &sColour : canStealFrom) {
                if (i == canStealFrom.size()-1) {
                  cout << sColour << "." << endl;
                } else {
                  cout << sColour << ", ";
                }
                ++i;
              }
              cout << "Choose a student to steal from." << endl;
              string otherStudent;
              cout << ">";
              cin >> otherStudent;
              Resource stolen = goose->steal(students.at(curTurn), getStudent(otherStudent)); //TODO: Floating point exception
              cout << "Student " << students.at(curTurn)->getStudentColour() << " steals ";
              if (stolen == Resource::CAFFEINE) cout << "Caffeine";
              if (stolen == Resource::LAB) cout << "Lab";
              if (stolen == Resource::LECTURE) cout << "Lecture";
              if (stolen == Resource::TUTORIAL) cout << "Tutorial";
              if (stolen == Resource::STUDY) cout << "Study";
              cout << " from student " << otherStudent << "." << endl;
            } else {
              cout << "Student " << students.at(curTurn)->getStudentColour() << " has no students to steal from." << endl;
            }
          } else {
            vector<vector<int>> before;
            for (auto &s : students) {
              before.emplace_back(s->getStudentResource());
            }
            board->giveResources(roll);
            vector<vector<int>> updated;
            for (auto &s : students) {
              updated.emplace_back(s->getStudentResource());
            }
            if (updated == before) {
              cout << "No students gained resources." << endl;
            } else {
              int i = 0;
              for (auto &s : students) {
                if (before.at(i) != updated.at(i)) {
                  cout << "Student " << s->getStudentColour() << " gained:" << endl;
                  if (before.at(i).at(0) != updated.at(i).at(0)) cout << updated.at(i).at(0) - before.at(i).at(0) << " Caffeines" << endl;
                  if (before.at(i).at(1) != updated.at(i).at(1)) cout << updated.at(i).at(1) - before.at(i).at(1) << " Labs" << endl;
                  if (before.at(i).at(2) != updated.at(i).at(2)) cout << updated.at(i).at(2) - before.at(i).at(2) << " Lectures" << endl;
                  if (before.at(i).at(3) != updated.at(i).at(3)) cout << updated.at(i).at(3) - before.at(i).at(3) << " Studies" << endl;
                  if (before.at(i).at(4) != updated.at(i).at(4)) cout << updated.at(i).at(4) - before.at(i).at(4) << " Tutorials" << endl;
                }
                ++i;
              }
            }
          }
          break;
        } else {
          cout << "Invalid command." << endl;
        }
      }
      /* - - - - - - - - - - - - - - - - - Dice Roll End - - - - - - - - - - - - - - - - - - - - */
      /* - - - - - - - - - - - - - - - - - Playing Turn - - - - - - - - - - - - - - - - - - - - */
      while (true) {
        cout << ">";
        cin >> cmd;
        if (cin.eof()) {
          break;
        } else if (cmd == "board") {
          printer->printBoard(board);
        } else if (cmd == "status") {
          for (auto &s: students) {
            printer->printStatus(s);
          }
        } else if (cmd == "criteria") {
          cout << students.at(curTurn)->getStudentColour() << "has completed:" << endl;
          string criteria;
          for (auto &c: students.at(curTurn)->getStudentCriteria()) {
            criteria += to_string(c) + " ";
          }
          cout << criteria << endl;
        } else if (cmd == "goal") {
          int i;
          cin >> i;
          int result = board->buildGoal(i, students.at(curTurn)); //1 == success
          if (result == 0) {
            cout << "You do not have enough resources." << endl;
          } else if (result == -1) {
            cout << "You cannot build here." << endl;
          }
        } else if (cmd == "complete") {
          int i;
          cin >> i;
          int result = board->buildCriterion(i, false, true, students.at(curTurn));
          if (result == 0) {
            cout << "You do not have enough resources." << endl;
          } else if (result == -1) {
            cout << "You cannot build here." << endl;
          }
        } else if (cmd == "improve") {
          int i;
          cin >> i;
          int result = board->buildCriterion(i, true, true, students.at(curTurn));
          if (result == 0) {
            cout << "You do not have enough resources." << endl;
          } else if (result == -1) {
            cout << "You cannot build here." << endl;
          }
        } else if (cmd == "trade") {
          string colour, give, take;
          cin >> colour >> give >> take;
          Resource toGive = sToRessource(give);
          Resource toTake = sToRessource(take);
          cout << students.at(curTurn)->getStudentColour() << " offers " << colour << " one " << give << " for one " << take << "." << endl;
          cout << "Does " << colour << " accept this offer?" << endl;
          cout << ">";
          string answer;
          cin >> answer;
          if (answer == "yes") {
            bool trade = students.at(curTurn)->trade(toGive, toTake, getStudent(colour));
            if (!trade) cout << "This trade is impossible, insufficient resources." << endl;
          }
        } else if (cmd == "next") {
          break;
        } else if (cmd == "save") {
          string file;
          cin >> file;
          saveGame(file);
        } else if (cmd == "help") {
          cout << "Valid commands:\nboard\nstatus\ncriteria\nachieve <goal>\ncomplete <criterion>\nimprove <criterion>\ntrade <colour> <give> <take>\nnext\nsave <file>\nhelp" << endl;
        } else {
          cout << "Invalid command." << endl;
        }
      }
      if (cin.eof()) {
        saveGame("backup.sv");
        break;
      }
      curTurn = (curTurn+1)%4;
      if (checkWin()) {
        endGame();
        break;
      }
    }
//  } catch (...) { }
}



void Game::endGame() {
  cout << "Would you like to play again?" << endl;
  string restart;
  cout << ">";
  cin >> restart;
  if (restart == "yes") {
    if (gameLoaded) {
      loadGame(fileToLoad);
    } else if (boardLoaded) {
      loadBoard(fileToLoad);
    } else {
      newGame();
    }
  } else if (restart == "no") {
    return;
  }
}
