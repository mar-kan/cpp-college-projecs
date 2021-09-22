#ifndef SCHOOLBUILDING_H
#define SCHOOLBUILDING_H


#include <iostream>
#include "Yard.h"
#include "Stair.h"
#include "Floor.h"
#include "Room.h"

class SchoolBuilding: public Room {

    Floor *floors[3]{};   //array of 3 floors of school
    Yard *yard;
    Stair *stair;

public:
    SchoolBuilding(int);
    ~SchoolBuilding();

    void enter(Student *);
    void print();
    void operate();

    bool canEnter();

    Yard *getYard() const;
    Floor *getFloorByNum(int) const;
    Stair *getStair() const;
};


#endif
