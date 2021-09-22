#ifndef STUDENT_H
#define STUDENT_H


#include <string>
#include <iostream>
using namespace std;

class Student {

    string name;
    int floor_num, class_num;

    string place_desc;  //stores name of place
    void * place;       //stores pointer to place

public:
    Student(string, int, int);
    ~Student();

    void print();

    void setPlace(void *place);
    void setPlaceDesc(const string &placeDesc);

    const string &getName() const;
    int getFloorNum() const;
    int getClassNum() const;

};


#endif
