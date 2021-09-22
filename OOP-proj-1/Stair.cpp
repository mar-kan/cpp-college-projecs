#include "Stair.h"


Stair::Stair(int capacity)    //initializes max capacity and null array of <capacity> students
{
    cout << "New Stairs have been created!" << endl;

    max_capacity = capacity;
    student_count = 0;

    students = new Student*[max_capacity];
}


Stair::~Stair()   //deletes students of stairs
{
    cout << "Stairs to be destroyed!" << endl;

    for (int i=0; i<student_count; i++)
        delete students[i];
    delete[] students;
}


bool Stair::enter(Student *student)  //given student enters stairs
{
    if (this->isFull())
        return false;

    cout << student->getName() << " enters stairs!"<< endl;
    students[student_count] = student;  //adds student in array
    student_count++;    //increases count of students

    student->setPlaceDesc("Stair"); //sets stairs as student's place
    student->setPlace(this);

    return true;
}


Student* Stair::exit(Student *student)   //given student exits stairs
{
    cout << student->getName() << " exits stairs!"<< endl;

    int i;
    for (i=0; i<student_count; i++) //finds and removes student from array
    {
        if (student->getName() == students[i]->getName())
            break;
    }
    for (int j=i; j<student_count; j++) //fixes rest of array so there are no gaps
    {
        students[j] = students[j+1];
    }
    student_count--;

    if (i==student_count)
        return nullptr;

    return student;
}


void Stair::print()  //prints stairs as requested
{
    cout << "People in stairs are: "<< endl;

    //prints all students in here
    for (int i=0; i<student_count; i++)
        students[i]->print();

    cout << endl;
}


bool Stair::isFull()     //returns if stairs are full
{
    return max_capacity < student_count;
}


Student * Stair::getStudentFromFloor(int floor_num)   //returns a student to go to specified floor
{
    for (int i=0; i<student_count; i++)
    {
        if (students[i]->getFloorNum() == floor_num)
            return students[i];
    }
    return nullptr; //no more students for this floor
}


int Stair::getStudentCount() const //returns num of students in stairs
{
    return student_count;
}
