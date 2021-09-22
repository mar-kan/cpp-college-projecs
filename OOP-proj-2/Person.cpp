#include "Person.h"


Person::Person(string n, int fl, int cl, int L, string t)   //creates person and prints all his info
{
    name = n;
    floor_num = fl;
    class_num = fl*10 + cl;
    inClass = false;
    tired = 0;
    Lp = L;
    type = t;

    cout << "A New "<<type<<" has been created!" << endl;
    printAll();
}


Person::~Person()   //deletes person and prints all his info
{
    cout << "A "<<type<<" to be destroyed!" << endl;
    printAll();
}


void Person::printNameAndTired()   //prints person's name
{
    cout << name <<", "<< tired << endl;
}


void Person::printAll()    //prints all person's info
{
    cout << "Name: "<< name<<endl << "Floor number: "<<floor_num<<endl<<"Class number: "<<class_num<<endl;
    if (inClass)
        cout << "Inside classroom" << endl;
    else
        cout << "Outside of classroom"<< endl;
    cout << "Tired points: "<< tired << endl<<endl;
}


//setters and getters
bool Person::isInClass() const
{
    return inClass;
}


int Person::getFloorNum() const
{
    return floor_num;
}


int Person::getClassNum() const
{
    return class_num;
}


const string &Person::getName() const
{
    return name;
}


void Person::setInClass(bool inClass)
{
    Person::inClass = inClass;
}
