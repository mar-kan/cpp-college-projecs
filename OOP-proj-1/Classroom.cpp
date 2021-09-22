#include "Classroom.h"
#include "utilities.h"


Classroom::Classroom(int capacity, int floor_num, int cl)  //initializes max capacity, class num, null array of <capacity> students
{
    cout << "A New Class has been created with number: " << cl << endl;

    max_capacity = capacity;
    student_count = 0;
    class_num = cl;

    students = new Student*[max_capacity];
    teacher = nullptr;  //teacher set later
}


Classroom::~Classroom()   //deletes students and teacher of class
{
    cout << "Class "<< class_num << " to be destroyed!" << endl;

    for (int i=0; i<student_count; i++)
        delete students[i];
    delete[] students;

    delete teacher;
}


bool Classroom::enter(Student *student)  //given student enters class
{
    if (teacher->isInClass() || this->isFull())
        return false;

    cout << student->getName() << " enters classroom!"<< endl;
    students[student_count] = student;  //adds student in array
    student_count++;    //increases count of students

    student->setPlaceDesc("Class"); //sets class as student's place
    student->setPlace(this);

    return true;
}


void Classroom::print()  //prints class as requested
{
    cout << "People in class "<< class_num << " are: " << endl;

    //prints all students in here
    for (int i=0; i<student_count; i++)
        students[i]->print();

    //print teacher
    cout << "The teacher is: "<< endl;
    teacher->print();
    cout << endl;
}


bool Classroom::isFull()     //returns if yard full
{
    return max_capacity < student_count;
}


//setters and getters
bool Classroom::teacherIsIn()   //returns if teacher is placed
{
    return teacher->isInClass();
}


void Classroom::setTeacher(Teacher *teacher)
{
    Classroom::teacher = teacher;
}


int Classroom::getClassNum() const
{
    return class_num;
}
