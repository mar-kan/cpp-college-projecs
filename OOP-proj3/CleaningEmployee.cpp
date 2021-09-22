#include "CleaningEmployee.h"


CleaningEmployee::CleaningEmployee(string n)
{
    name = n;
    workOn = false;        //no work

    cout << "Cleaning Employee just created!" << endl;
}


void CleaningEmployee::Report(string process)
{
    cout << process << " is OK" << endl;
}


CleaningEmployee::~CleaningEmployee()
{
    cout << "Cleaning Employee to be destroyed!" << endl;
}


string CleaningEmployee::getName()
{
    return name;
}


bool CleaningEmployee::getWorkOn()
{
    return workOn;
}


void CleaningEmployee::setWorkOn(bool workOn)
{
    CleaningEmployee::workOn = workOn;
}
