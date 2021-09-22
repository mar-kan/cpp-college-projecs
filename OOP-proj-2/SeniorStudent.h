#ifndef SENIORSTUDENT_H
#define SENIORSTUDENT_H

#include "Student.h"

class SeniorStudent: public Student{

public:
    SeniorStudent(string n, int fl, int cl, int Ls) : Student(n, fl, cl, Ls) {/*initializes student*/}
    virtual ~SeniorStudent()= default;;
};


#endif
