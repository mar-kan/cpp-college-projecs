#include "CargoBay.h"


CargoBay::CargoBay()
{
    descr = "this is cargo bay";
    process = nullptr;
    ready_check = false;
    equip = new EquipmentCompartment();

    cout << "Cargo Bay just created!" << endl;
}


CargoBay::~CargoBay()
{
    cout << "Cargo Bay to be destroyed!" << endl;
    delete process;
    delete equip;
}


//getters

const string &CargoBay::getDescr() const
{
    return descr;
}


EquipmentCompartment *CargoBay::getEquip() const
{
    return equip;
}


bool CargoBay::isReadyCheck() const
{
    return ready_check;
}


void CargoBay::setReadyCheck(bool readyCheck)
{
    ready_check = readyCheck;
}


Employee *CargoBay::getProcess() const {
    return process;
}
