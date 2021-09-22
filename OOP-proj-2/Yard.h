#ifndef YARD_H
#define YARD_H


#include <iostream>
#include "Student.h"
#include "Room.h"
using namespace std;

class Yard: public Room {

public:
    Yard() : Room("Yard"){}
    virtual ~Yard()=default;
};


#endif
