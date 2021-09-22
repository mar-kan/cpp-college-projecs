#include "SecurityEmployee.h"
#include "PassengerCompartment.h"
#include "CargoBay.h"
#include "EquipmentCompartment.h"
#include "Plane.h"


SecurityEmployee::SecurityEmployee(string n)
{
    name = n;
    workOn = false;        //no work

    cout << "Security Employee just created!" << endl;
}


void SecurityEmployee::Report(string process)
{
    cout << process << " is OK" << endl;
}


SecurityEmployee::~SecurityEmployee()
{
    cout << "Security Employee to be destroyed!" << endl;
}


string SecurityEmployee::getName()
{
    return name;
}


bool SecurityEmployee::getWorkOn()
{
    return workOn;
}


void SecurityEmployee::setWorkOn(bool workOn)
{
    SecurityEmployee::workOn = workOn;
}
