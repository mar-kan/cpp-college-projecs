#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "SeniorClass.h"
#include "JuniorClass.h"
#include "Corridor.h"
#include "Room.h"
using namespace std;

class Floor: public Room {

    int floor_num;

    JuniorClass * juniorClasses[3]{}; //array of 3 junior classes of floor
    SeniorClass * seniorClasses[3]{}; //array of 3 senior classes of floor
    Corridor *corridor;

public:
    Floor(int,int);
    ~Floor();

    void enter(Student *);
    void print();
    void operate();

    Class * getClassByNum(int) const;
    Corridor *getCorridor() const;
    int getFloorNum() const;
};


#endif
