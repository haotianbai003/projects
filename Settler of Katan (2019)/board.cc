#include "board.h"

using namespace std;

Board::  Board () {
      int i = 0;
      while (i < 54) {
          //criterion[i] = new Criterion(nullptr, 0, i);
          criterion.emplace_back(new Criterion(nullptr, 0, i));
          i += 1;       // level is 0 when no achievement
      }
      i = 0;
      while (i < 72) {
          //goal[i] = new Goal(nullptr, i);
          goal.emplace_back(new Goal(nullptr, i));
          i += 1;
      }
      i = 0;
          int tut = 3;
          int stud = 3;
          int caf = 4;
          int lab = 4;
          int lec = 4;
          int net = 1;
          int two = 1;
          int twelve = 1;
          int three = 2;
          int four = 2;
          int five = 2;
          int six = 2;
          int eight = 2;
          int nine = 2;
          int ten = 2;
          int eleven = 2;


      while (i < 19) {
          Resource r = roll_resource (&tut, &stud, &caf, &lab, &lec, &net);
          int value;
          if (r == NETFLIX) {
              value = 7;
          } else {
              value = roll_value(&two, &twelve, &three, &four, &five, &six, &eight, &nine, &ten, &eleven);
          }
          vector<Criterion *> c (6, nullptr);

          if (i == 0) {
              c[0] = criterion[0];
              c[1] = criterion[1];
              c[2] = criterion[3];
              c[3] = criterion[4];
              c[4] = criterion[8];
              c[5] = criterion[9];
          } else if (i == 18) {
              c[0] = criterion[44];
              c[1] = criterion[45];
              c[2] = criterion[49];
              c[3] = criterion[50];
              c[4] = criterion[52];
              c[5] = criterion[53];
          } else if (i == 11) {
              c[0] = criterion[25];
              c[1] = criterion[26];
              c[2] = criterion[31];
              c[3] = criterion[32];
              c[4] = criterion[37];
              c[5] = criterion[38];
          } else if ((i == 1) || (i == 2)) {
              int k0 = (2*i) + (2*(i/2));
              int k2 = k0 + 5;
              int k4 = k2 + 6;
               c[0] = criterion[k0];
              c[1] = criterion[k0 + 1];
              c[2] = criterion[k2];
              c[3] = criterion[k2 + 1];
              c[4] = criterion[k4];
              c[5] = criterion[k4 + 1];
          } else if ((i == 14) || (i == 16) || (i == 17)) {
              int k0 = (2*i) + (i / 3);
              int k2 = k0 + 6;
              int k4 = k2 + 5;
              c[0] = criterion[k0];
              c[1] = criterion[k0 + 1];
              c[2] = criterion[k2];
              c[3] = criterion[k2 + 1];
              c[4] = criterion[k4];
              c[5] = criterion[k4 + 1];
          } else {
              int k0 = (2*i) + ((i / 3) - 1);
              int k2 = k0 + 6;
              int k4 = k2 + 6;
               c[0] = criterion[k0];
              c[1] = criterion[k0 + 1];
              c[2] = criterion[k2];
              c[3] = criterion[k2 + 1];
              c[4] = criterion[k4];
              c[5] = criterion[k4 + 1];
          }


          vector<Goal *> g (6, nullptr);
          if (i == 0) {
              g[0] = goal[0];
              g[1] = goal[1];
              g[2] = goal[2];
              g[3] = goal[6];
              g[4] = goal[7];
              g[5] = goal[10];
          } else if (i == 18) {
              g[0] = goal[61];
              g[1] = goal[64];
              g[2] = goal[65];
              g[3] = goal[69];
              g[4] = goal[70];
              g[5] = goal[71];
          } else if ((i == 2) || (i == 16)){
              int k0 = (2*i) + (5 * (i / 4));
              int k1 = k0 + 3;
              int k3 = k1 + 8;
              int k5 = k3 + 4;
              g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];
          } else if (i == 17) {
                   g[0] = goal[53];
              g[1] = goal[57];
              g[2] = goal[58];
              g[3] = goal[65];
              g[4] = goal[66];
              g[5] = goal[68];
          } else if (i == 1) {
                   g[0] = goal[3];
              g[1] = goal[5];
              g[2] = goal[6];
              g[3] = goal[13];
              g[4] = goal[14];
              g[5] = goal[18];
          } else if ((i== 6) || (i == 11)) {
              int k0 = (3*i) + (2*(i / 7));
              int k1 = k0 + 3;
              int k3 = k1 + 9;
              int k5 = k3 + 5;
                 g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];

          } else if ((i == 7) || (i == 12)) {
              int k0 = (3*i) - ((i % 3) / 2);
              int k1 = k0 + 4;
              int k3 = k1 + 9;
              int k5 = k3 + 4;
              g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];
          } else if ((i % 5) == 0) {
              int k0 = (3*i) - ((2 * i) % 6);
              int k1 = k0 + 5;
              int k3 = k1 + 8;
              int k5 = k3 + 4;
              g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];
          } else if ((i == 3) || (i == 8) || (i == 13)) {
              int k0 = (3*i) + (2 * (i / 6));
              int k1 = k0 + 3;
              int k3 = k1 + 8;
              int k5 = k3 + 6;
                  g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];
          } else {
              int k0;
              if (i == 4) {
                  k0 = 10;
              } else if (i == 9) {
                  k0 = 27;
              } else {
                  k0 = 44;
              }
              int k1 = k0 + 4;
              int k3 = k1 + 8;
              int k5 = k3 + 5;
              g[0] = goal[k0];
              g[1] = goal[k1];
              g[2] = goal[k1 + 1];
              g[3] = goal[k3];
              g[4] = goal[k3 + 1];
              g[5] = goal[k5];
          }
          //tiles[i] = new Tile(r, i, value, c, g, false);
          tiles.emplace_back(new Tile(r, i, value, c, g, false));
          i += 1;
      }
  }

string Board::saveBoard() { 
	string s = "";
	int i = 0;
	while (i < 19) {
		if (tiles[i]->getResource() == CAFFEINE) {
			s += "0";
		} else if (tiles[i]->getResource() == LAB) {
			s += "1";
		} else if (tiles[i]->getResource() == LECTURE) {
			s += "2";
		} else if (tiles[i]->getResource() == STUDY) {
			s += "3";
		} else if (tiles[i]->getResource() == TUTORIAL){
			s += "4";
		} else {
			s += "5";
		}
		s += " ";
		s += to_string(tiles[i]->getVal());
		s += " ";
		i += 1;
	}
	s.pop_back();
	return s;
}


void Board:: loadStringBoard(string s) {
	stringstream ss;
	ss <<s;
	vector<int> values;
	vector<int> rs;
	int num;
	int r1;
	while (!ss.eof()) {
		string temp;
		ss >> temp;
		stringstream(temp) >> r1;
		rs.emplace_back(r1);
		ss >> temp;
		stringstream(temp) >> num;
		values.emplace_back(num);
	}

int i = 0;
while (i < 19) {
	Resource r;
	if (rs[i] == 0) {
		r = CAFFEINE;
		tiles[i]->updateResource(r);
	} else if (rs[i] == 1) {
		r = LAB;
		tiles[i]->updateResource(r);
	} else if (rs[i] == 2) {
		r = LECTURE;
		tiles[i]->updateResource(r);
	} else if (rs[i] == 3) {
		r = STUDY;
		tiles[i]->updateResource(r);
	} else if (rs[i] == 4) {
		r = TUTORIAL;
		tiles[i]->updateResource(r);
	} else {
		r = NETFLIX;
		tiles[i]->updateResource(r);
	}
	int n = values[i];
	tiles[i]->updateVal(n);
	i += 1;
}
}




void Board::loadGoal(int pos, Student *s) {
	Goal *g = goal[pos];
    s->addGoal(g);
}


void Board::loadCriterion(int pos, int completion, Student *s) {
    s->addCriterion(criterion[pos], completion);
}

void Board:: giveResources(int n) {
    int i = 0;
    while (i < 19) {
        if(tiles[i]->getVal() == n) {
            tiles[i]->notify();
        }
        i += 1;
    }
}

Tile * Board::getTile (int n) {
    return tiles[n];
}

bool Board::checkCriterion (int n) {
         vector<int> result;
	 BoardMap b;
b.getNeighCritOfCrit(n, result);
int i = 0;
int len = result.size();
while (i < len) {
	if (criterion[result[i]]->isAchieved()) {
		return false;
	}
	i += 1;
}
return true;
}

// either I or Bill which check if student has adjascent goal/criterion
bool Board:: checkGoal(int n) {
    return goal[n]->isAchieved();
}


int Board:: buildGoal(int n, Student *s) {
	if ((n < 0) || (n > 71)) {
		return -1;
	}
    if(checkGoal(n)) {
        return -1;
    } // either you or bill will check if student has an adjacent goal r criterion to this goal.
   return s->achieveGoal(goal[n]); // tell marco to talk to bill about numbering
}


int Board:: buildCriterion(int n, bool is_improve, bool useResources, Student *s) {
	if((n < 0) || (n > 53)) {
		return -1;
	}
    if(useResources == false) {
        if((criterion[n]->isAchieved()) || (checkCriterion(n) == false)) {
            return -1;
        }
      loadCriterion(n, 1, s);
      return 1;
    }
    if (is_improve == true) {
    return s->improveCriterion(criterion[n]);
    } else {
       if((criterion[n]->isAchieved()) || (checkCriterion(n) == false)) {
          return -1;
       }
      return s->completeCriterion(criterion[n]);
    }
}



Board::~Board() {
    int i = 0;
    int n = goal.size();
    while (i < n ){
        delete goal[i];
        i += 1;
    }
    i = 0;
    n = criterion.size();
    while (i < n) {
        delete criterion[i];
        i += 1;
    }
    i = 0;
    n = tiles.size();
    while(i < n) {
        delete tiles[i];
        i += 1;
    }
}




Resource Board:: roll_resource(int *tut, int *stud, int *caf, int *lab, int *lec, int *net) {
          int resource_roll = rand()%6 + 1;
          Resource r;
          while (1) {
              if (resource_roll == 1) {
                  if (*tut >= 1) {
                      r = TUTORIAL;
                      *tut -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }
              } else if (resource_roll == 2) {
                  if (*stud >= 1) {
                      r = STUDY;
                      *stud -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }
              } else if (resource_roll == 3) {
                  if (*caf >= 1) {
                      r = CAFFEINE;
                      *caf -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }
              } else if (resource_roll == 4) {
                  if (*lab >= 1) {
                      r = LAB;
                      *lab -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }
              } else if (resource_roll == 5) {
                  if (*lec >= 1) {
                      r = LECTURE;
                      *lec -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }

              } else {
                  if (*net >= 1) {
                      r = NETFLIX;
                      *net -= 1;
                      break;
                  } else {
                     resource_roll = rand()%6 + 1;
                     continue;
                  }
              }
              break;
          }
          return r;
}


int Board::roll_value(int *two, int *twelve, int *three, int *four, int *five, int *six, int *eight, int *nine, int *ten, int *eleven) {
    int v1 = (rand()%6) + 1;
    int v2 = (rand()%6) + 1;
    int v = v1 + v2;
    while (1) {
        if (v == 2) {
            if (*two >= 1) {
                *two -= 1;
                break;
            } else {
                v1 = (rand()%6) + 1;
                v2 = (rand()%6) + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 12) {
            if (*twelve >= 1) {
                *twelve -= 1;
                break;
            } else {
                v1 = (rand()%6) + 1;
                v2 = (rand()%6) + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 3) {
            if (*three >= 1) {
                *three -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 4) {
            if (*four >= 1) {
                *four -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 5) {
            if (*five >= 1) {
                *five -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 6) {
            if (*six >= 1) {
                *six -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 8) {
            if (*eight >= 1) {
                *eight-= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 9) {
            if (*nine >= 1) {
                *nine -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 10) {
            if (*ten >= 1) {
                *ten -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else if (v == 11) {
            if (*eleven >= 1) {
                *eleven -= 1;
                break;
            } else {
                v1 = rand()%6 + 1;
                v2 = rand()%6 + 1;
                v = v1 + v2;
                continue;
            }
        } else {
		v1 = rand()%6 + 1;
		v2 = rand()%6 + 1;
		v = v1 + v2;
		continue;
	}
        break;
    }
    return v;
}

void spaces(int n, ostream &out) {
    int i = 0;
    while (i < n) {
        out << " ";
        i += 1;
    }
}


void printValsSet(Criterion* a, Goal* b, Criterion* c, ostream &out) {
    string a1;
    string b1;
    string c1;
    if (a->getOwner() != nullptr) {
        a1 += (a->getOwner())->getStudentChar();   // getChar() gets the first letters of colour of student (in capitals)
        if (a->getLevel() == 1) {
		a1 += 'A';
	} else if (a->getLevel() == 2) {
		a1 += 'M';
	} else {
		a1 += 'E';
	}

    } else {
        a1 = to_string(a->getPos());
    }

     if (c->getOwner() != nullptr) {
        c1 += (c->getOwner())->getStudentChar();   // getChar() gets the first letters of colour of student (in capitals)
            if (c->getLevel() == 1) {
	    c1 += 'A';
	    } else if (c->getLevel() == 2) {
		    c1 += 'M';
	    } else {
		    c1 += 'E';
	    } 
    }else {
        c1 = to_string(c->getPos());
    }
    if (b->getOwner() != nullptr) {
       b1 += (b->getOwner())->getStudentChar();
    } else {
        b1 = to_string(b->getPos());
    }

    if (a1.length() > 1) {
		out << "|" << a1 << "|";
	} else{
		out << "| " << a1 << "|";
	}

	if (b1.length() > 1 ) {
		out << "--" << b1 << "--";
	} else{
		out << "-- " << b1 << "--";
	}

	if (c1.length() > 1) {
		out << "|" << c1 << "|";
	} else{
		out << "| " << c1 << "|";
	}
}

void slashes(ostream &out) {
    out << "/";
    int i = 0;
    while (i < 12) {
        out << " ";
	i += 1;
    }
    out << "\\";
}



void tileRow(Goal *g1, Tile *t, Goal *g2, ostream &out) {
    string s1;
    string s2;
       if (g1->getOwner() != nullptr) {
	   s1 += (g1->getOwner())->getStudentChar();
	   s1 += 'A';
    } else {
	    if(g1->getPos() < 10) {
		    s1 += " ";
		    s1 += to_string(g1->getPos());
	    } else {
		    s1 = to_string(g1->getPos());
	    }
    }

    if (g2->getOwner() != nullptr) {
	 s2 += (g2->getOwner())->getStudentChar();
	 s2 += 'A';
    } else {
	    if(g2->getPos() < 10) {
		    s2 += " ";
		    s2 += to_string(g2->getPos());
	    } else {
		    s2 = to_string(g2->getPos());
	    }
    }
    string s3 = to_string(t->getPos());   // add getPos() to Tile
		if (s3.length() > 1){
			out << s1 << "      " << s3;
		}else{
			out << s1 << "       " << s3;
		}
		out << "     "  << s2;	
}


void printResource(Resource r, ostream &out) {
    	if (r == TUTORIAL){ // do Resource::TUTORIAL
		out << "/" << "    TUTORIAL    " << "\\";
	}else if (r == STUDY){
		out << "/" << "      STUDY     " << "\\";
	}else if (r == LAB){
		out << "/" << "      LAB       " << "\\";
	}else if(r == LECTURE){
		out << "/" << "     LECTURE    " << "\\";
	}else if (r == NETFLIX){
		out << "/" << "     NETFLIX    " << "\\";
	}else if (r == CAFFEINE){
		out << "/" << "    CAFFEINE    " << "\\";
	}
}

void printValue (int n, ostream &out) {
    if (n > 9){
		out << "       " << n << "       ";
	} else if (n == 7){
		out << "        " << " " << "       ";
	} else {
		out << "        " << n << "       ";
	}
}


void printGoose(bool goose, ostream &out) {
    if (!goose){
		out << "                ";
	}else{
		out << "      Geese     ";
	}
}



void oneCriterion(Criterion *c, ostream& out) {
    string c1;
      if (c->getOwner() != nullptr) {
        c1 += (c->getOwner())->getStudentChar();   // getChar() gets the first letters of colour of student (in capitals)
        if(c->getLevel() == 1) {
		c1 += 'A';
	} else if (c->getLevel() == 2) {
		c1 += 'M';
	} else {
		c1 += 'E';
	}
    } else {
        c1 = to_string(c->getPos());
    }
    if (c1.length() > 1){
		out << "|" << c1 << "|";
	}else{
		out << "| " << c1 << "|";
	}

}

void oneGoal(Goal * g, ostream& out) {
    string s;
    if (g->getOwner() != nullptr) {
	 s += (g->getOwner())->getStudentChar();
	 s += 'A';
    } else {
        s = to_string(g->getPos());
	if(s.length() == 1) {
		out << " ";
	}
    }
    out << s;

}

void Board:: printBoard(ostream &out) {
// use friend output overloaded operator instead
out<<tiles[2]->getVal()<<endl;
    	//Line 1
	spaces(37, out);
	printValsSet(criterion[0], goal[0], criterion[1], out);
	out << endl;

	//Line 2
	spaces(37, out);
	slashes(out);
	out << endl;

	//Line 3
	spaces(35, out);
	tileRow(goal[1], tiles[0], goal[2], out);
	out <<endl;

	//Line 4
	spaces(35, out);
	printResource(tiles[0]->getResource(), out);
	out << endl;

	//Line 5
	spaces(22, out);
	printValsSet(criterion[2], goal[3], criterion[3], out);
	printValue(tiles[0]->getVal(), out);
	printValsSet(criterion[4], goal[4], criterion[5], out);
	out << endl;

	//Line 6
	spaces(22, out);
	slashes(out);
	printGoose(tiles[0]->hasGoose(), out);
	slashes(out);
	out << endl;

	//Line 7
	spaces(20, out);
	tileRow(goal[5], tiles[1], goal[6], out);
	spaces(13, out);
	tileRow(goal[7], tiles[2], goal[8], out);
	out<< endl;


	//Line 8
	spaces(20, out);
	printResource(tiles[1]->getResource(), out);
	spaces(12, out);
	printResource(tiles[2]->getResource(), out);
	out <<endl;

	//Line 9
	spaces(7, out);
	printValsSet(criterion[6], goal[9], criterion[7], out);
	printValue(tiles[1]->getVal(), out);
	printValsSet(criterion[8], goal[10], criterion[9], out);
	printValue(tiles[2]->getVal(), out);
	printValsSet(criterion[10], goal[11], criterion[11], out);
	out << endl;

	//Line 10
	spaces(7, out);
	slashes(out);
	printGoose(tiles[1]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[2]->hasGoose(), out);
	slashes(out);
	out <<endl;

	//Line 11
	spaces(5, out);
	tileRow(goal[12], tiles[3], goal[13], out);
	spaces(13, out);
	tileRow(goal[14], tiles[4], goal[15], out);
	spaces(13, out);
	tileRow(goal[16], tiles[5], goal[17], out);
	out <<endl;

	//Line 12
	spaces(5, out);
	printResource(tiles[3]->getResource(), out);
	spaces(12, out);
	printResource(tiles[4]->getResource(), out);
	spaces(12, out);
	printResource(tiles[5]->getResource(), out);
	out<<endl;

	//Line 13
	spaces(2, out);
	oneCriterion(criterion[12], out);
	printValue(tiles[3]->getVal(), out);
	printValsSet(criterion[13], goal[18], criterion[14], out);
	printValue(tiles[4]->getVal(), out);
	printValsSet(criterion[15], goal[19], criterion[16], out);
	printValue(tiles[5]->getVal(), out);
	oneCriterion(criterion[17], out);
	out<<endl;

	//Line 14
	spaces(5, out);
	out << "\\";
	printGoose(tiles[3]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[4]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[5]->hasGoose(), out);
	out << "/";
	out << endl;

	//Line 15
	spaces(5, out);
	oneGoal(goal[20], out);
	spaces(13, out);
	tileRow(goal[21], tiles[6], goal[22], out);
	spaces(13, out);
	tileRow(goal[23], tiles[7], goal[24], out);
	spaces(13, out);
	oneGoal(goal[25], out);
	out << endl;

	//Line 16
	spaces(7, out);
	out << "\\";
	spaces(12, out);
	printResource(tiles[6]->getResource(), out);
	spaces(12, out);
	printResource(tiles[7]->getResource(), out);
	spaces(12, out);
	out << "/";
	out << endl;

	// Line 17
	spaces(7, out);
	printValsSet(criterion[18], goal[26], criterion[19], out);
	printValue(tiles[6]->getVal(), out);
	printValsSet(criterion[20], goal[27], criterion[21], out);
	printValue(tiles[7]->getVal(), out);
	printValsSet(criterion[22], goal[28], criterion[23], out);
	out << endl;

	//Line 18
	spaces(7, out);
	slashes(out);
	printGoose(tiles[6]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[7]->hasGoose(), out);
	slashes(out);
	out <<endl;

	//Line 19
	spaces(5, out);
	tileRow(goal[29], tiles[8], goal[30], out);
	spaces(13, out);
	tileRow(goal[31], tiles[9], goal[32], out);
	spaces(13, out);
	tileRow(goal[33], tiles[10], goal[34], out);
	out <<endl;

	//Line 20
	spaces(5, out);
	printResource(tiles[8]->getResource(), out);
	spaces(12, out);
	printResource(tiles[9]->getResource(), out);
	spaces(12, out);
	printResource(tiles[10]->getResource(), out);
	out<<endl;

	//Line 21
	spaces(2, out);
	oneCriterion(criterion[24], out);
	printValue(tiles[8]->getVal(), out);
	printValsSet(criterion[25], goal[35], criterion[26], out);
	printValue(tiles[9]->getVal(), out);
	printValsSet(criterion[27], goal[36], criterion[28], out);
	printValue(tiles[10]->getVal(), out);
	oneCriterion(criterion[29], out);
	out<<endl;

	//Line 22
	spaces(5, out);
	out << "\\";
	printGoose(tiles[8]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[9]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[10]->hasGoose(), out);
	out << "/";
	out << endl;

	//Line 23
	spaces(5, out);
	oneGoal(goal[37], out);
	spaces(13, out);
	tileRow(goal[38], tiles[11], goal[39], out);
	spaces(13, out);
	tileRow(goal[40], tiles[12], goal[41], out);
	spaces(13, out);
	oneGoal (goal[42], out);
	out << endl;

	//Line 24
	spaces(7, out);
	out << "\\";
	spaces(12, out);
	printResource(tiles[11]->getResource(), out);
	spaces(12, out);
	printResource(tiles[12]->getResource(), out);
	spaces(12, out);
	out << "/";
	out << endl;

	//Line 25
	spaces(7, out);
	printValsSet(criterion[30], goal[43], criterion[31], out);
	printValue(tiles[11]->getVal(), out);
	printValsSet(criterion[32], goal[44], criterion[33], out);
	printValue(tiles[12]->getVal(), out);
	printValsSet(criterion[34], goal[45], criterion[35], out);
	out << endl;

	//Line 26
	spaces(7, out);
	slashes(out);
	printGoose(tiles[11]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[12]->hasGoose(), out);
	slashes(out);
	out <<endl;

	//Line 27
	spaces(5, out);
	tileRow(goal[46], tiles[13], goal[47], out);
	spaces(13, out);
	tileRow(goal[48], tiles[14], goal[49], out);
	spaces(13, out);
	tileRow(goal[50], tiles[15], goal[51], out);
	out <<endl;

	//Line 28
	spaces(5, out);
	printResource(tiles[13]->getResource(), out);
	spaces(12, out);
	printResource(tiles[14]->getResource(), out);
	spaces(12, out);
	printResource(tiles[15]->getResource(), out);
	out<<endl;

	//Line 29
	spaces(2, out);
	oneCriterion(criterion[36], out);
	printValue(tiles[13]->getVal(), out);
	printValsSet(criterion[37], goal[52], criterion[38], out);
	printValue(tiles[14]->getVal(), out);
	printValsSet(criterion[39], goal[53], criterion[40], out);
	printValue(tiles[15]->getVal(), out);
	oneCriterion(criterion[41], out);
	out<<endl;

	//Line 30
	spaces(5, out);
	out << "\\";
	printGoose(tiles[13]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[14]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[15]->hasGoose(), out);
	out << "/";
	out << endl;

	//Line 31
	spaces(5, out);
	oneGoal (goal[54], out);
	spaces(13, out);
	tileRow(goal[55], tiles[16], goal[56], out);
	spaces(13, out);
	tileRow(goal[57], tiles[17], goal[58], out);
	spaces(13, out);
	oneGoal(goal[59], out);
	out << endl;

	//Line 32
	spaces(7, out);
	out << "\\";
	spaces(12, out);
	printResource(tiles[16]->getResource(), out);
	spaces(12, out);
	printResource(tiles[17]->getResource(), out);
	spaces(12, out);
	out << "/";
	out << endl;

	//Line 33
	spaces(7, out);
	printValsSet(criterion[42], goal[60], criterion[43], out);
	printValue(tiles[16]->getVal(), out);
	printValsSet(criterion[44], goal[61], criterion[45], out);
	printValue(tiles[17]->getVal(), out);
	printValsSet(criterion[46], goal[62], criterion[47], out);
	out << endl;

	//Line 34
	spaces(20, out);
	out << "\\";
	printGoose(tiles[16]->hasGoose(), out);
	slashes(out);
	printGoose(tiles[17]->hasGoose(), out);
	out << "/";
	out << endl;

	//Line 35
	spaces(20, out);
	oneGoal(goal[63], out);
	spaces(13, out);
	tileRow(goal[64], tiles[18], goal[65], out);
	spaces(13, out);
	oneGoal( goal[66], out);
	out << endl;

	//Line 36
	spaces(22, out);
	out << "\\";
	spaces(12, out);
	printResource(tiles[18]->getResource(), out);
	spaces(12, out);
	out << '/';
	out << endl;

	//Line 37
	spaces(22, out);
	printValsSet(criterion[48], goal[67], criterion[49], out);
	printValue(tiles[18]->getVal(), out);
	printValsSet(criterion[50], goal[68], criterion[51], out);
	out << endl;

	//Line 38
	spaces(35, out);
	out << "\\";
	printGoose(tiles[18]->hasGoose(), out);
	out << "/";
	out <<endl;

	//Line 39
	spaces(35, out);
	oneGoal (goal[69], out);
	spaces(13, out);
	oneGoal(goal[70], out);
	out << endl;

	//Line 40
	spaces(37, out);
	out << "\\";
	spaces(12, out);
	out << "/";
	out << endl;

	//Line 41
	spaces(37, out);
	printValsSet(criterion[52], goal[71], criterion[53], out);
	out << endl;

}
