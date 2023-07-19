// student.h
#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>
#include "criterion.h"
#include "goal.h"
#include "dice.h"
#include "resource.h"

class BoardMap;
extern int SEED;
extern const BoardMap BM;

// resourceType keeps track of the usable resources in printing order
const std::vector<Resource> resourceType = {CAFFEINE, LAB,
    LECTURE, STUDY, TUTORIAL};

class Student {
    private:
        char colour;
        std::vector<int> resource;
        std::vector<Goal*> goal;
        std::vector<Criterion*> criterion;
        Dice dice;
    public:
        // ctors
        Student(char colour);

        // if possible, removes giveAmt of resource give, increase takeAmt
        //     of take in current student; does the opposite in *s
        bool trade(Resource give, Resource take, Student* s, 
            int giveAmt = 1, int takeAmt = 1);

        // Dice management
        // updates the dice to roll loaded == b
        void updateDice(bool b);
        // rolls the dice and returns the result
        int rollDice();

        // Criterion management
        // will attempt to build / improve Criterion at *c
        //    returns -1 if I don't own this, 0 if not enough resource, 1 if success
        int improveCriterion(Criterion* c);
        // will attempt to complete criterion at *c
        //    returns -1 if I don't own this, 0 if not enough resource, 1 if success
        int completeCriterion(Criterion* c);
        // forcefully add criterion
        void addCriterion(Criterion* c, int level);
        
        // Goal management
        // forcefully add goal
        void addGoal(Goal* g);
        // will attempt to achieve Goal at *g
        int achieveGoal(Goal* g);
        
        // Resource management
        // returns how much resources (int) the student has
        int getStudentResourceCount();
        // will change current student's Resource r by 'amount'
        void changeResource(Resource r, int amount); // ammount can be +/-
        // randomly select a resource from student
        Resource rndSelect();


        // student information
        // return student's colour
        std::string getStudentColour();
        // return student's colour as char
        char getStudentChar();
        // return student's resources in order of:
        //     CAFFEINE, LAB, LECTURE, STUDY, then TUTORIAL
        std::vector<int> getStudentResource();
        // return student's completed goals
        std::vector<int> getStudentGoals();
        // return student's completed criteria followed by level
        std::vector<int> getStudentCriteria();
};


#endif
