#include "Student.h"


Student::Student(string n, int fl, int cl, int L): Person(n, fl, cl, L, "Student")    //creates student outside of classroom and not tired
{
    //initializes person
}


void Student::attend() //attends class for one hour
{
    tired += Lp;
}
