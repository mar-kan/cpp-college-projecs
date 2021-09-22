//Kanellaki Maria-Anna - 1115201400060


#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <iostream>
#include "Object.h"
#include "SecurityEmployee.h"
#include "MaintenanceEmployee.h"
#include "CleaningEmployee.h"
#include "CargoBay.h"
#include "list.h"
#include "PassengerCompartment.h"

using namespace std;


class Plane: public Object, list{
    string descr;
    string title;
    int capacity;
    Employee * process;

    CargoBay *cargo;
    EquipmentCompartment * equips[3];
    int n;
    list * spaces = new(list);              //list of Passenger Compartments


public:
    Plane(string,string,int);
    bool Ready();
    bool SecurityCheck(SecurityEmployee *);
    bool MaintenanceCheck(MaintenanceEmployee *);
    bool CleaningCheck(CleaningEmployee *);
    int CalculatePassengerSpaces(int);
    virtual ~Plane();

    const string &getDescr() const;
    const string &getTitle() const;
    int getCapacity() const;
    Employee *getProcess() const;
    CargoBay *getCargo() const;
    EquipmentCompartment *const *getEquips() const;
    int getN() const;
    list *getSpaces() const;
};


#endif
