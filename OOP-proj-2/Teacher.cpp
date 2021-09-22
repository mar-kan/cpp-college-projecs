#include "Teacher.h"

#include <utility>
#include "Class.h"


Teacher::Teacher(string n, int fl, int cl, int L): Person(n, fl, cl, L, "Teacher")  //creates teacher outside of classroom and not tired
{
    //initializes person
}


void Teacher::place()   //places teacher in his classroom
{
    inClass = true;
}


void Teacher::teach() //teaches for one hour
{
    tired += Lp;
}