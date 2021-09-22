#ifndef JUNIORSTUDENT_H
#define JUNIORSTUDENT_H


#include "Student.h"

class JuniorStudent: public Student{

public:
    JuniorStudent(string n, int fl, int cl, int Lj) : Student(n, fl, cl, Lj){/*initializes student*/};
    virtual ~JuniorStudent()= default;;
};


#endif