#include "Object.h"

Object::Object()
{
    id = rand();                    //random unique numbers
    descr = "object";
    tString = toString();
    cout << "Object just created!" << endl;
}


bool Object::Equal(Object *obj1)
{
    return obj1->id == id;
}


Object * Object::Clone()
{
    Object * clone = new Object();

    clone->id = id;
    clone->descr = descr;
    clone->tString = tString;

    return clone;
}


string Object::toString()
{
    return to_string(id) + " " + descr;
}


Object::~Object()
{
    cout << "Object to be destroyed!" << endl;
}


int Object::getId() const
{
    return id;
}


const string &Object::getDescr() const
{
    return descr;
}


const string &Object::getTString() const
{
    return tString;
}