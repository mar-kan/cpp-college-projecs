#include "PrivateCompartment.h"


PrivateCompartment::PrivateCompartment()
{
    cout << "PrivateCompartment just created!" << endl;
}


PrivateCompartment::~PrivateCompartment()
{
    cout << "PrivateCompartment to be destroyed!" << endl;
}


const string &PrivateCompartment::getDescr() const
{
    return descr;
}


const string &PrivateCompartment::getProcess() const
{
    return process;
}
