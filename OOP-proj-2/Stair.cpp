#include "Stair.h"


Stair::Stair() : Room("Stair")
{
    //initializes Room
}


int Stair::getStudentPosForFloor(int floor_num)     //returns position of a student that wants to go to given floor_num
{
    int count = students->size();
    for (int i=0; i<count; i++)
    {
        if (students->at(i)->getFloorNum() == floor_num)
            return i;
    }
    return -1;  //returns -1 if there are none left for this floor
}