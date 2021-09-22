#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

using namespace std;


class Object
{
    int id;                         //takes random ints in increasing order
    string descr;
    string tString;

public:
    Object();
    bool Equal(Object *);
    Object * Clone();
    string toString();
    virtual ~Object();

    int getId() const;
    virtual const string &getDescr() const;
    const string &getTString() const;
};


#endif
