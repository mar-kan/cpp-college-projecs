#ifndef STRING_H
#define STRING_H

#include <string>
#include <iostream>
#include "Object.h"
using namespace std;


class String: public Object {
    string str;
    string descr;

public:
    String(string);
    int Length();
    void Clear();
    void Concat(string);
    char At(int);
    void UpdateAt(int, char);
    void Print();
    virtual ~String();

    void clearStr();
    string &getStr();

    const string &getDescr() const;
};


#endif
