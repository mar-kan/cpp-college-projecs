#ifndef CORRIDOR_H
#define CORRIDOR_H


#include <iostream>
#include "Student.h"
#include "Classroom.h"

using namespace std;

class Corridor {

    int max_capacity;
    int student_count;

    Student ** students;    //array of students that are in stairs

    //all corridors same capacity

public:
    Corridor(int);
    ~Corridor();

    bool enter(Student *);
    Student* exit(Student *);
    void print();
    bool isFull();

    Student * getStudentFromClass(int);
    int getStudentCount() const;

};


#endif
