#ifndef ROOM_H
#define ROOM_H


#include <vector>
#include "Student.h"

class Room {

    string type;                  //defines to which type of room the object refers to

protected:
    //vector of students that are in this room
    vector<Student *>* students;

public:
    Room(string);
    ~Room();

    void enter(Student *);
    Student * exit(int);
    void print();

    int getStudentCount();
    Student * getStudentAt(int);
};


#endif
