#ifndef STAIR_H
#define STAIR_H


#include <iostream>
#include <list>
#include "Student.h"
#include "Room.h"

using namespace std;

class Stair: public Room {                     //initializes stairs with empty list of students

public:
    Stair();
    virtual ~Stair()=default;

    int getStudentPosForFloor(int floor_num);
};


#endif
