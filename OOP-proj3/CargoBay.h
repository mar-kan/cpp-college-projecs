#ifndef CARGOBAY_H
#define CARGOBAY_H

#include <iostream>
#include <string>
#include "EquipmentCompartment.h"
#include "PrivateCompartment.h"
#include "Employee.h"

using namespace std;


class CargoBay: public PrivateCompartment {
    string descr;
    Employee * process;
    bool ready_check;
    EquipmentCompartment * equip;

public:
    CargoBay();
    virtual ~CargoBay();

    const string &getDescr() const;
    bool isReadyCheck() const;
    EquipmentCompartment *getEquip() const;
    void setReadyCheck(bool readyCheck);
    Employee *getProcess() const;
};


#endif
