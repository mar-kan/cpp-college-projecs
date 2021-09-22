#include "Yard.h"


Yard::Yard(int capacity)    //initializes max capacity and null array of <capacity> students
{
    cout << "A New Schoolyard has been created!" << endl;

    max_capacity = capacity;
    student_count = 0;

    students = new Student*[max_capacity];
}


Yard::~Yard()   //deletes students of yard
{
    cout << "A Schoolyard to be destroyed!" << endl;

    for (int i=0; i<student_count; i++)
        delete students[i];
    delete[] students;
}


bool Yard::enter(Student *student)  //given student enters yard
{
    if (this->isFull())   //if yard full, function returns
        return false;

    cout << student->getName() << " enters schoolyard!"<< endl;
    students[student_count] = student;  //adds student in array
    student_count++;    //increases count of students

    student->setPlaceDesc("Yard"); //sets yard as student's place
    student->setPlace(this);

    return true;    //returned if entering was successful
}


Student* Yard::exit(Student *student)   //given student exits yard
{
    cout << student->getName() << " exits schoolyard!"<< endl;

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


void Yard::print()  //prints yard as requested
{
    cout << "People in schoolyard are: "<< endl;

    //prints all students in here
    for (int i=0; i<student_count; i++)
        students[i]->print();

    cout << endl;
}


bool Yard::isFull()     //returns if yard full
{
    return max_capacity < student_count;
}


Student * Yard::getStudentInPos(int pos)    //returns the student from yard who is in position <pos>
{
    if (pos >= student_count)
        return nullptr;

    return students[pos];
}



int Yard::getStudentCount() const //returns number of students in yard
{
    return student_count;
}
