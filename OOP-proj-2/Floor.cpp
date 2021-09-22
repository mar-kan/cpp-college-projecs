#include "Floor.h"


Floor::Floor(int num, int cClass) : Room("Floor")  //initializes floor <num> with new empty corridor and 6 classes
{
    cout << "A New Floor has been created with number: " << num << endl;

    floor_num = num;
    corridor = new Corridor();

    for (int i=0; i<3; i++)
    {
        int class_num = floor_num*10 + i+1;   //class num is a 2-digit num. 1st one represents floor and 2nd class

        //creates 3 junior and 3 senior classes
        juniorClasses[i] = new JuniorClass(cClass, floor_num, class_num); //classes 1to3
        seniorClasses[i] = new SeniorClass(cClass, floor_num, class_num+3); //classes 4to6
    }
}


Floor::~Floor()     //deletes corridor and classes, overrides room's destructor
{
    //cout << "Floor "<<floor_num<<" to be destroyed!" << endl;

    delete corridor;
    for (int i=0; i<3; i++)
    {
        delete juniorClasses[i];
        delete seniorClasses[i];
    }
}


void Floor::operate()   //operates floor's classrooms
{
    for (int i=0; i<3; i++)
    {
        juniorClasses[i]->operate();
        seniorClasses[i]->operate();
    }
}


void Floor::enter(Student *student)  //given student enters floor, overrides room's enter
{
    cout << student->getName() << " enters floor!"<< endl;
    corridor->enter(student);   //enters corridor
}


void Floor::print() //prints floor, overrides room's print
{
    cout << "Floor number "<< floor_num <<" contains:  "<< endl;
    corridor->print();

    for (int i=0; i<3; i++)
    {
        juniorClasses[i]->print();
        seniorClasses[i]->print();
    }
}


//getters
Class * Floor::getClassByNum(int num) const //returns class with number = num
{
    for (int i=0; i<3; i++)
    {
        if (juniorClasses[i]->getClassNum() == num)
            return juniorClasses[i];
        if (seniorClasses[i]->getClassNum() == num)
            return seniorClasses[i];
    }
    return nullptr;
}


Corridor *Floor::getCorridor() const
{
    return corridor;
}


int Floor::getFloorNum() const
{
    return floor_num;
}
