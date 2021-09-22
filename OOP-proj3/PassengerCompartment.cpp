#include "PassengerCompartment.h"


PassengerCompartment::PassengerCompartment(bool inArea)
{
    descr = "passengers";
    process = "";
    ready_check = false;
    indoors = inArea;
    cout << "PassengerCompartment just created!" << endl;
}


PassengerCompartment::~PassengerCompartment()
{
    cout << "PassengerCompartment to be destroyed!" << endl;
}


const string &PassengerCompartment::getDescr() const
{
    return descr;
}


const string &PassengerCompartment::getProcess() const
{
    return process;
}


bool PassengerCompartment::isReadyCheck() const
{
    return ready_check;
}


bool PassengerCompartment::isIndoors() const
{
    return indoors;
}


void PassengerCompartment::setReadyCheck(bool readyCheck)
{
    ready_check = readyCheck;
}
