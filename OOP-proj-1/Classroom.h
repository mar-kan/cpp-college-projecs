#ifndef CLASS_H
#define CLASS_H


#include <iostream>
#include "Student.h"
#include "Teacher.h"
using namespace std;

class Classroom {

    int class_num;
    int max_capacity, student_count;

    Student ** students;    //array of students that are in class
    Teacher * teacher;

public:
    Classroom(int, int, int);
    ~Classroom();

    bool enter(Student *);
    void print();

    bool isFull();
    bool teacherIsIn();
    void setTeacher(Teacher *teacher);

    int getClassNum() const;
};


#endif
