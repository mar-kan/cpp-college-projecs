#ifndef TEACHER_H
#define TEACHER_H


#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Teacher: public Person {

public:
    Teacher(string, int, int, int);
    virtual ~Teacher()=default;
    void place();
    void teach();
};


#endif
