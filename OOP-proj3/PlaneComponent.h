#ifndef PLANECOMPONENT_H
#define PLANECOMPONENT_H

#include <string>
#include <iostream>
#include "Object.h"
using namespace std;

class PlaneComponent: public Object {

    string descr;
    string process;

public:
    PlaneComponent();
    ~PlaneComponent();

    const string &getDescr() const;
    const string &getProcess() const;
};


#endif