#include "SchoolBuilding.h"


SchoolBuilding::SchoolBuilding(int cClass) : Room("SchoolBuilding") //constructor of school building
{                                                                   //initializes 3 floors, yard and stair
    cout << "A New School has been created!" << endl;

    for (int i=0; i<3; i++)
        floors[i] = new Floor(i+1, cClass);  //i+1 represents floor num

    yard = new Yard();
    stair = new Stair();
}


SchoolBuilding::~SchoolBuilding()   //deletes all  compartments of school building
{
    cout << "A School to be destroyed!" << endl;

    for (auto & floor : floors)
        delete floor;

    delete stair;
    delete yard;
}


void SchoolBuilding::enter(Student *student)    //student enters school building
{
    cout << student->getName() << " enters building!"<< endl;
    yard->enter(student);
}


void SchoolBuilding::print()       //prints school building as requested
{
    cout << "School life consists of: "<< endl;
    //yard->print();
    //stair->print();

    for (auto & floor : floors)
        floor->print();
}


void SchoolBuilding::operate() //operates school for one hour
{
    for (auto & floor : floors)
        floor->operate();
}


//getters
Yard *SchoolBuilding::getYard() const
{
    return yard;
}


Floor * SchoolBuilding::getFloorByNum(int num) const    //returns floor with floor num = num
{
    for (auto floor : floors)
    {
        if (floor->getFloorNum() == num)
            return floor;
    }
    return nullptr;
}


Stair *SchoolBuilding::getStair() const
{
    return stair;
}
