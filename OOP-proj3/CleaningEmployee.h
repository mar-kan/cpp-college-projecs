#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

#ifndef CLEANINGEMPLOYEE_H
#define CLEANINGEMPLOYEE_H


class CleaningEmployee: public Employee {
    string name;
    bool workOn;

public:
    CleaningEmployee(string);
    void Report(string);
    ~CleaningEmployee();

    string getName();
    bool getWorkOn();
    void setWorkOn(bool workOn);
};


#endif
