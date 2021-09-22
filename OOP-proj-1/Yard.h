#ifndef YARD_H
#define YARD_H


#include <iostream>
#include "Student.h"
using namespace std;

class Yard {

    int student_count;
    int max_capacity;

    Student ** students;    //array of students that are in yard

public:
    explicit Yard(int);
    ~Yard();

    bool enter(Student *);
    Student* exit(Student *);

    void print();
    bool isFull();

    Student * getStudentInPos(int);
    int getStudentCount() const;
};


#endif
