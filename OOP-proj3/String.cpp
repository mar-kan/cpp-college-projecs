#include "String.h"


String::String(string s)
{
    str = s;
    descr = "stringObject";
    cout << "String just created!" << endl;
}


int String::Length()
{
    return str.length();
}


void String::Clear()
{
    str = nullptr;
}


void String::Concat(string str2)
{
    str += str2;
}


char String::At(int pos)
{
    return str[pos];
}


void String::UpdateAt(int pos, char newc)
{
    str[pos] = newc;
}


void String::Print()
{
    cout << str << endl;
}


String::~String()
{
    cout << "String to be destroyed!" << endl;
}


string &String::getStr()
{
    return str;
}


void String::clearStr()
{
    str = "";
}


const string &String::getDescr() const
{
    return descr;
}
