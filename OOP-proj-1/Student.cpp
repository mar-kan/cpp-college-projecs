#include "Student.h"


Student::Student(string n, int fl, int cl)  //creates student outside of school
{
    name = n;
    floor_num = fl;
    class_num = fl+10 * cl;

    place_desc = "outside";
    place = nullptr;
    cout << "A new Student has been created!" << endl;

    //prints student's info
    cout << "Name: "<< name<<endl <<"Floor number: "<<floor_num<<endl<<"Class number: "<<class_num<<endl<<"Place: "<<place_desc << endl<<endl;
}


Student::~Student() //deletes student
{
    //delete place;
    cout << "A Student to be destroyed!" << endl;

    //prints student's info
    cout << "Name: "<< name<<endl << "Floor number: "<<floor_num<<endl<<"Class number: "<<class_num<<endl<<"Place: "<<place_desc << endl<<endl;
}


void Student::print()   //prints student name
{
    cout << name << endl;
}


//setters and getters
void Student::setPlace(void *place)
{
    Student::place = place;
}


void Student::setPlaceDesc(const string &placeDesc)
{
    place_desc = placeDesc;
}


const string &Student::getName() const
{
    return name;
}


int Student::getFloorNum() const
{
    return floor_num;
}


int Student::getClassNum() const
{
    return class_num;
}
