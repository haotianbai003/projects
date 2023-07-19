#include "dice.h"
#include <iostream>
using namespace std;

Dice::Dice(){};

void Dice::setLoaded(bool l) {
  loaded = l;
}

int Dice::roll() {
  if (loaded) {
    int roll;
    while (true) {
      cout << "Input a roll between 2 and 12:" << endl;
      cin >> roll;
      if ((roll < 2) || (roll > 12)) {
        cout << "Invalid roll" << endl;
      } else {
        return roll;
        break;
      }
    }
  } else {
  	int r1 = rand() % 6 + 1;
  	int r2 = rand() % 6 + 1;
    return (r1 + r2);
  }
}
