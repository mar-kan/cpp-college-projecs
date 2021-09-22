#include "Room.h"
#include "Floor.h"


Room::Room(string t)    //initializes max capacity and null array of <capacity> students
{
    cout << "A New "<< t << " has been created!" << endl;
    type = t;
    students = new vector<Student*>();
}


Room::~Room()   //deletes room
{
    //all the other rooms are deleted here
    cout << "A "<<type<<" to be destroyed!" << endl;

    vector<Student*>::iterator it;
    for(it=students->begin(); it!=students->end(); it++)
        delete *it;
    delete students;
}


void Room::enter(Student *student)  //given student enters room
{
    cout << student->getName() << " enters "<<type<<" !"<< endl;
    students->push_back(student);
}


Student * Room::exit(int pos)   //student in position pos of vector exits room
{
    Student * student = students->at(pos);
    cout << student->getName() << " exits "<<type<<" !"<< endl;
    students->erase(students->begin()+pos);

    return student; //returns pointer to student that exited
}


void Room::print()  //prints room and students in it
{
    cout << "People in "<<type<<" are: "<< endl;

    //prints all students in here
    vector<Student*>::iterator it;
    for(it=students->begin(); it!=students->end(); it++)
        (*it)->printNameAndTired();

    cout << endl;
}


int Room::getStudentCount()
{
    return students->size();
}


Student * Room::getStudentAt(int pos)
{
    return students->at(pos);
}