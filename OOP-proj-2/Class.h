#ifndef CLASS_H
#define CLASS_H


#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Room.h"
using namespace std;

class Class: public Room {

    int max_capacity;
    int class_num;

    string type;            //junior or senior class
    Teacher * teacher;

public:
    Class(int, int, int, string);
    ~Class();

    void enter(Student *);
    void print();
    void operate();

    bool isFull() const;
    void setTeacher(Teacher *teacher);
    int getClassNum() const;
};


#endif
