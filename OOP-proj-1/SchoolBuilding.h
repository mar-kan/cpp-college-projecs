#ifndef SCHOOLBUILDING_H
#define SCHOOLBUILDING_H


#include <iostream>
#include "Yard.h"
#include "Stair.h"
#include "Floor.h"

class SchoolBuilding {

    Floor *floors[3];   //array of 3 floors of school
    Yard *yard;
    Stair *stair;

    int student_count;
    Student ** outStudents;


public:
    SchoolBuilding(int,int,int,int);
    ~SchoolBuilding();

    void enter();
    void print();
};


#endif
