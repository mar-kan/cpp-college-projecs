#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Employee: public Object {
    string name;
    string workOn;

public:
    Employee();
    virtual void Report() {};
    virtual ~Employee();
};


#endif
