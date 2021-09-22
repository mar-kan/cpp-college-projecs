#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()                                            //date constructor generates a random date
{
    day = rand()%29 + 1;
    month = rand()%12 + 1;
    year = rand()% 20 + 2000;
}


void Date::PrintDate()
{
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}


Date::~Date()
{

}