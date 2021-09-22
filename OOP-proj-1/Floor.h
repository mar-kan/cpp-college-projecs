#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include "Classroom.h"
#include "Corridor.h"
using namespace std;

class Floor {

    int floor_num;

    Classroom * classes[6]; //array of 6 classes of floor
    Corridor *corridor;

public:
    Floor(int,int,int);
    ~Floor();

    bool enter(Student *);
    void print();

    Classroom * getClassByNum(int) const;
    Corridor *getCorridor() const;
    int getFloorNum() const;
};


#endif
