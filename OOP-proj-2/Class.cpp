#include "Class.h"
#include "utilities.h"


Class::Class(int capacity, int floor_num, int cl, string t) : Room("Class")  //initializes max capacity, class num, null array of <capacity> studentArray
{
    cout << "A New Class has been created with number: " << cl << endl;
    class_num = cl;
    max_capacity = capacity;

    type = t;
    teacher = nullptr;  //teacher set later
}


Class::~Class()   //deletes teacher of class
{
    //cout << "Class "<< class_num << " to be destroyed!" << endl;
    delete teacher;
}


void Class::operate()   //teacher teaches and all studentArray attend class for 1 hour
{
    teacher->teach();
    int count = students->size();
    for (int i=0; i<count; i++)
        students->at(i)->attend();
}


void Class::enter(Student *student)  //given student enters class
{
    if (this->isFull())
        return;

    cout << student->getName() << " enters Class !"<< endl;
    student->setInClass(true);
    students->push_back(student);
}


void Class::print()  //prints class as requested
{
    cout << "People in class "<< class_num << " are: " << endl;

    //prints all studentArray in here
    int count = students->size();
    for (int i=0; i<count; i++)
        students->at(i)->printNameAndTired();

    //prints teacher
    cout << "The teacher is: "<< endl;
    teacher->printNameAndTired();
    cout << endl;
}


bool Class::isFull() const     //returns if class is full
{
    return max_capacity < int(students->size());
}


void Class::setTeacher(Teacher *teacher)
{
    Class::teacher = teacher;
}


int Class::getClassNum() const
{
    return class_num;
}
