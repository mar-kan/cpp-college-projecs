#include "MaintenanceEmployee.h"
#include "EquipmentCompartment.h"
#include "CargoBay.h"


MaintenanceEmployee::MaintenanceEmployee(string n)
{
    name = n;
    workOn = false;        //no work

    cout << "Maintenance Employee just created!" << endl;
}


void MaintenanceEmployee::Report(string process)
{
    if (workOn)
        cout << process << " is OK" << endl;
}


MaintenanceEmployee::~MaintenanceEmployee()
{
    cout << "Maintenance Employee to be destroyed!" << endl;
}


string MaintenanceEmployee::getName()
{
    return name;
}


bool MaintenanceEmployee::getWorkOn()
{
    return workOn;
}


void MaintenanceEmployee::setWorkOn(bool workOn)
{
    MaintenanceEmployee::workOn = workOn;
}
