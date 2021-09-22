#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

class Student: public Person {

public:
    Student(string, int, int, int);
    virtual ~Student()=default;
    void attend();
};


#endif
