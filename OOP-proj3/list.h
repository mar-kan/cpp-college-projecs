#ifndef LIST_H
#define LIST_H
#include "PassengerCompartment.h"
#include "SecurityEmployee.h"
#include "CleaningEmployee.h"

//list to manage passenger compartments of plane

class list {

protected:                  //so that list can be easily managed by Plane class
    struct node
    {
        PassengerCompartment *getComp() const;

        PassengerCompartment * comp;
        node * next;
    };
    node * head;

public:
    list();
    void Insert(PassengerCompartment *);
    bool CheckPassengerCompartments(SecurityEmployee *);
    bool CheckPassengerCompartments(CleaningEmployee *);
    virtual ~list();

    node *getHead() const;
};


#endif
