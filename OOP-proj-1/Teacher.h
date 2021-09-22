#ifndef TEACHER_H
#define TEACHER_H


#include <iostream>
#include <string>
using namespace std;

class Teacher {

    string name;
    int floor_num, class_num;
    bool inClass;

public:
    Teacher(string, int, int);
    ~Teacher();

    void place();
    void print();

    bool isInClass() const;
    int getFloorNum() const;
    int getClassNum() const;
};


#endif
