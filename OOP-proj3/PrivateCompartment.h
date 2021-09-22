#ifndef PRIVATECOMPARTMENT_H
#define PRIVATECOMPARTMENT_H

#include <string>
#include <iostream>
#include "PlaneComponent.h"

using namespace std;


class PrivateCompartment: public PlaneComponent {

    string descr;
    string process;

public:
    PrivateCompartment();
    ~PrivateCompartment();

    const string &getDescr() const;
    const string &getProcess() const;
};


#endif
