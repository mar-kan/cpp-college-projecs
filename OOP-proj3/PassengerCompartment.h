#ifndef PASSENGERCOMPARTMENT_H
#define PASSENGERCOMPARTMENT_H

#include <string>
#include <iostream>
#include "PlaneComponent.h"
using namespace std;

class PassengerCompartment: public PlaneComponent {

    string descr;
    string process;
    bool ready_check;
    bool indoors;

public:
    PassengerCompartment(bool);
    virtual ~PassengerCompartment();

    const string &getDescr() const;
    const string &getProcess() const;
    bool isReadyCheck() const;
    bool isIndoors() const;
    void setReadyCheck(bool readyCheck);
};


#endif
