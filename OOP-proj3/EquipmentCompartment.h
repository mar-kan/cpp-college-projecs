#ifndef EQUIPMENTCOMPARTMENT_H
#define EQUIPMENTCOMPARTMENT_H

#include <iostream>
#include <string>
#include "PrivateCompartment.h"
#include "Object.h"

using namespace std;

class EquipmentCompartment: public Object {

    string descr;
    string process;
    bool ready_check;

public:
    EquipmentCompartment();
    virtual ~EquipmentCompartment();

    const string &getDescr() const;
    const string &getProcess() const;
    bool isReadyCheck() const;
    void setReadyCheck(bool readyCheck);
};


#endif
