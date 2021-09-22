#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>
using namespace std;


class Person {

protected:
    string name;
    int floor_num, class_num;
    bool inClass;
    int tired;      //tiredness points
    int Lp;         //tiredness increases by Ls points
    string type;    //defines type of person this object refers to

public:
    Person(string, int, int, int, string);
    ~Person();

    void printNameAndTired();
    void printAll();

    bool isInClass() const;
    int getFloorNum() const;
    int getClassNum() const;
    const string &getName() const;
    void setInClass(bool inClass);
};


#endif
