#include "list.h"


list::list()                                                           //create empty list
{
    head = nullptr;
}


void list::Insert(PassengerCompartment * compart)
{
    node * temp = new node;

    temp->comp = compart;
    temp->next = nullptr;

    if (!head)
        head = temp;

    else
    {
        node * curr = head;
        while (curr->next)
            curr = curr->next;

        curr->next = temp;
    }
}


bool list::CheckPassengerCompartments(SecurityEmployee * emp)                   //security check
{
    node * temp = head;
    bool ready = false;

    while (temp)
    {
        if (!temp->comp->isReadyCheck())
        {
            emp->setWorkOn(true);
            cout << "Checking Passenger Compartment" << endl;
            emp->Report("Passenger Compartment");

            if (temp->comp->isIndoors())
            {
                cout << "Checking Passenger Compartment's indoor area" << endl;
                emp->Report("Passenger Compartment's indoor area");
            }

            temp->comp->setReadyCheck(true);
            emp->setWorkOn(false);
        }
        ready = temp->comp->isReadyCheck();

        temp = temp->next;
    }

    return ready;
}


bool list::CheckPassengerCompartments(CleaningEmployee * emp)                   //maintenance check
{
    node * temp = head;
    bool ready = false;

    while (temp)
    {
        temp->comp->setReadyCheck(false);               //set them to false to check them for cleaning
        if (!temp->comp->isReadyCheck())
        {
            emp->setWorkOn(true);
            cout << "Checking Passenger Compartment" << endl;
            emp->Report("Passenger Compartment");

            if (temp->comp->isIndoors())
            {
                cout << "Checking Passenger Compartment's indoor area" << endl;
                emp->Report("Passenger Compartment's indoor area");
            }

            temp->comp->setReadyCheck(true);
            emp->setWorkOn(false);
        }
        ready = temp->comp->isReadyCheck();

        temp = temp->next;
    }

    return ready;
}


list::~list()
{
    node * curr = head;
    node * temp;

    while (curr != nullptr)
    {
        temp = curr;
        curr = curr->next;
        delete temp->comp;
        delete temp;
    }
}




