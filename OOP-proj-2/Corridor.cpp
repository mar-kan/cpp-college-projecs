#include "Corridor.h"


Corridor::Corridor() : Room("Corridor")
{
    //initializes Room
}


int Corridor::getStudentPosFromClass(int class_num)      //returns position of a student that wants to go to given class_num
{
    int count = students->size();
    for (int i=0; i<count; i++)
    {
        if (students->at(i)->getClassNum() == class_num)
            return i;
    }
    return -1;  //returns -1 if there are none left for this class
}