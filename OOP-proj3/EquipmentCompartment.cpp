#include "EquipmentCompartment.h"


EquipmentCompartment::EquipmentCompartment()
{
    descr = "this is an equipment compartment";
    process = "";
    ready_check = false;
    cout << "Equipment Compartment just created!" << endl;
}


EquipmentCompartment::~EquipmentCompartment()
{
    cout << "Equipment Compartment to be destroyed!" << endl;
}


const string &EquipmentCompartment::getDescr() const
{
    return descr;
}


const string &EquipmentCompartment::getProcess() const
{
    return process;
}


bool EquipmentCompartment::isReadyCheck() const
{
    return ready_check;
}


void EquipmentCompartment::setReadyCheck(bool readyCheck)
{
    ready_check = readyCheck;
}
