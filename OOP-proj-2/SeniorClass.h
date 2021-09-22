#ifndef SENIORCLASS_H
#define SENIORCLASS_H

#include "Class.h"

class SeniorClass : public Class {

public:
    SeniorClass(int cClass, int floor_num, int class_num) : Class(cClass, floor_num, class_num, "Senior") {};
    virtual ~SeniorClass()=default;
};
#endif
