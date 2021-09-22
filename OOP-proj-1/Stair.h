#ifndef STAIR_H
#define STAIR_H


#include <iostream>
#include "Student.h"

using namespace std;

class Stair {

    int max_capacity;
    int student_count;

    Student ** students;    //array of students that are in stairs

public:
    Stair(int);
    ~Stair();

    bool enter(Student *);
    Student* exit(Student *);

    void print();
    bool isFull();

    Student * getStudentFromFloor(int);
    int getStudentCount() const;
};


#endif
