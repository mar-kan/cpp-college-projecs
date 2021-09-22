#include "PlaneComponent.h"


PlaneComponent::PlaneComponent()
{
    cout << "PlaneComponent just created!" << endl;
}


PlaneComponent::~PlaneComponent()
{
    cout << "PlaneComponent to be destroyed!" << endl;
}


const string &PlaneComponent::getDescr() const
{
    return descr;
}


const string &PlaneComponent::getProcess() const
{
    return process;
}
