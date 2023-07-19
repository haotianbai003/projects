// Goal.h
#ifndef Goal_H
#define Goal_H

class Student;

class Goal {
    private:
        Student* owner;
        int pos;
    public:
        Goal(Student* owner = nullptr, int pos = 0);
        Student* getOwner();
        bool isAchieved();
        void achieveGoal(Student* s);
        int getPos();
};

#endif
