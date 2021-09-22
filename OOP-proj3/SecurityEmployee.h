#ifndef SECURITYEMPLOYEE_H
#define SECURITYEMPLOYEE_H

#include <iostream>
#include "Employee.h"

using  namespace std;


class SecurityEmployee : public Employee {
    string name;
    bool workOn;

public:
    SecurityEmployee(string);
    void Report(string process);
    ~SecurityEmployee();

    string getName();
    bool getWorkOn();
    void setWorkOn(bool workOn);
};


#endif
