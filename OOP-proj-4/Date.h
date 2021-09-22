#ifndef DATE_H
#define DATE_H


class Date                                                  //represents the dates for all classes
{
    int day;
    int month;
    int year;

public:
    Date();
    void PrintDate();
    virtual ~Date();
};


#endif
