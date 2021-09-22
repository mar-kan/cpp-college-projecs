#ifndef CORRIDOR_H
#define CORRIDOR_H


#include <iostream>
#include <list>
#include "Student.h"
#include "Class.h"
#include "Room.h"

using namespace std;

class Corridor: public Room {

public:
    Corridor();
    virtual ~Corridor()=default;

    int getStudentPosFromClass(int);
};


#endif
