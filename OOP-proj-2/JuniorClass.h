#ifndef JUNIORCLASS_H
#define JUNIORCLASS_H

#include "Class.h"

class JuniorClass : public Class {

public:
    JuniorClass(int cClass, int floor_num, int class_num) : Class(cClass, floor_num, class_num, "Junior") {};
    virtual ~JuniorClass()=default;
};
#endif
