#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

#ifndef MAINTENANCEEMPLOYEE_H
#define MAINTENANCEEMPLOYEE_H


class MaintenanceEmployee: public Employee {
    string name;
    bool workOn;

public:
    MaintenanceEmployee(string);
    void Report(string);
    ~MaintenanceEmployee();

    string getName();
    bool getWorkOn();
    void setWorkOn(bool workOn);
};


#endif
