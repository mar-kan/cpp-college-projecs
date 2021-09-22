#include "Corridor.h"


Corridor::Corridor(int capacity)    //initializes max capacity and null array of <capacity> students
{
    cout << "A New Corridor has been created!" << endl;

    max_capacity = capacity;
    student_count = 0;

    students = new Student*[max_capacity];
}


Corridor::~Corridor()   //deletes students of corridor
{
    cout << "A Corridor to be destroyed!" << endl;

    for (int i=0; i<student_count; i++)
        delete students[i];
    delete[] students;
}


bool Corridor::enter(Student *student)  //given student enters corridor
{
    if (this->isFull())
        return false;

    cout << student->getName() << " enters corridor!"<< endl;
    students[student_count] = student;  //adds student in array
    student_count++;    //increases count of students

    student->setPlaceDesc("Corridor"); //sets corridor as student's place
    student->setPlace(this);

    return true;
}


Student* Corridor::exit(Student *student)   //given student exits corridor
{
    cout << student->getName() << " exits corridor!"<< endl;

    int i;
    for (i=0; i<student_count; i++) //finds and removes student from array
    {
        if (student->getName() == students[i]->getName())
        {
            student = students[i];
            students[i] = nullptr;
            break;
        }
    }
    for (int j=i; j<student_count; j++) //fixes rest of array so there are no gaps
    {
        students[j] = students[j+1];
    }
    student_count--;

    if (i==student_count)
        return nullptr;

    return student; //returns student that exited
}


void Corridor::print()  //prints corridor as requested
{
    cout << "People in corridor are: "<< endl;

    //prints all students in here
    for (int i=0; i<student_count; i++)
            students[i]->print();

    cout << endl;
}


bool Corridor::isFull() //returns if corridor full
{
    return max_capacity < student_count;
}


Student * Corridor::getStudentFromClass(int class_num)   //returns a student to go to specified floor
{
    for (int i=0; i<student_count; i++)
    {
        if (students[i]->getClassNum() == class_num)
            return students[i];
    }
    return nullptr; //no more students for this class
}


int Corridor::getStudentCount() const //returns student count
{
    return student_count;
}
