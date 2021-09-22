#include "Floor.h"


Floor::Floor(int num, int cClass, int cCor)   //initializes floor <num> with new empty corridor and classes
{
    cout << "A New Floor has been created with number: " << num << endl;

    floor_num = num;
    corridor = new Corridor(cCor);

    for (int i=0; i<6; i++)
    {
        int class_num = floor_num*10 + i+1;   //class num is a 2-digit num. 1st one represents floor and 2nd class
        classes[i] = new Classroom(cClass, floor_num, class_num);
    }
}


Floor::~Floor()     //deletes corridor and classes
{
    cout << "Floor "<<floor_num<<" to be destroyed!" << endl;

    delete corridor;
    for (auto & classe : classes)
        delete classe;
}


bool Floor::enter(Student *student)  //given student enters floor
{

    cout << student->getName() << " enters floor!"<< endl;
    return corridor->enter(student);   //enters corridor
}


void Floor::print() //prints floor as requested
{
    cout << "Floor number "<< floor_num <<" contains:  "<< endl;
    corridor->print();

    for (auto & classe : classes)
        classe->print();
}


//getters
Classroom * Floor::getClassByNum(int num) const //returns class with number = num
{
    for (auto classe : classes)
    {
        if (classe->getClassNum() == num)
            return classe;
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
