#include "Teacher.h"

#include <utility>
#include "Classroom.h"


Teacher::Teacher(string n, int fl, int cl)  //creates teacher outside of classroom
{
    name = n;
    floor_num = fl;
    class_num = fl+10 * cl;
    inClass = false;

    cout << "A New Teacher has been created!" << endl;
    
    //prints teacher's info
    cout <<"Name: "<<name<<endl<<"Floor: "<<floor_num<<endl<<"Class: "<<class_num<<endl<<"Place: outside of classroom"<<endl<<endl;  
}


Teacher::~Teacher() //deletes teacher
{
    cout << "A Teacher to be destroyed!" << endl;

    
    //prints teacher's info
    cout <<"Name: "<<name<<endl<<"Floor: "<<floor_num<<endl<<"Class: "<<class_num<<endl<<"Place: ";

    if (inClass)
	cout << "Classroom "<< endl<<endl;  
    else
	cout << "outside of classroom"<<endl<<endl;
}


void Teacher::place()   //places teacher in his classroom
{
    inClass = true;
}


void Teacher::print()   //prints teacher name
{
    cout << name << endl;
}


//setters and getters
bool Teacher::isInClass() const
{
    return inClass;
}


int Teacher::getFloorNum() const
{
    return floor_num;
}


int Teacher::getClassNum() const
{
    return class_num;
}
