#ifndef DICE_H
#define DICE_H

class Dice {
  bool loaded = false;
 public:
  Dice();
  void setLoaded(bool l);
  int roll();
};

#endif

