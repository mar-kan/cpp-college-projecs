#include "Plane.h"

Plane::Plane(string d,string t,int c)
{
    descr = d;
    title = t;
    capacity = c;
    process = nullptr;          //no employees working yet

    //creates
    cargo = new CargoBay;

    int i;
    for (i=0; i<3; i++)
    {
        equips[i] = new EquipmentCompartment;
    }

    n = CalculatePassengerSpaces(capacity);
    for (i=0; i<n; i++)
    {
        PassengerCompartment * temp = new PassengerCompartment("no");
        spaces->Insert(temp);
    }


    cout << "Plane just created!" << endl;
}


bool Plane::Ready()                             //if any of planes compartments is not ready returns false
{
    if (!cargo->isReadyCheck())
        return false;

    int i;

    for (i=0; i<3; i++)
    {
        if (!equips[i]->isReadyCheck())
            return false;
    }

    node * temp = head;

    while (temp)
    {
        if (!temp->comp->isReadyCheck())
            return false;
    }

    return true;
}


bool Plane::SecurityCheck(SecurityEmployee * emp)               //puts security employee to work in all spaces
{
    if (emp->getWorkOn())
    {
        cout << "Employee already working" << endl;
        return false;
    }

    cout << "Security Employee working:" << endl;
    process = emp;

    if (!cargo->isReadyCheck())
    {
        emp->setWorkOn(true);
        cout << "Checking Cargo Bay" << endl;
        emp->Report("Cargo Bay");

        cout << "Checking Cargo Bay's Equipment Compartment" << endl;
        emp->Report("Cargo Bay's Equipment Compartment");

        cargo->setReadyCheck(true);
        emp->setWorkOn(false);
    }

    int i;
    for (i=0; i<3; i++)
    {
        if (!equips[i]->isReadyCheck())
        {
            emp->setWorkOn(true);
            cout << "Checking Equipment Compartment" << endl;
            emp->Report("Equipment Compartment");
            equips[i]->setReadyCheck(true);
            emp->setWorkOn(false);
        }
    }

    process = nullptr;
    return cargo->isReadyCheck() && equips[0]->isReadyCheck() && equips[1]->isReadyCheck() && equips[2]->isReadyCheck() && spaces->CheckPassengerCompartments(emp);
}


bool Plane::MaintenanceCheck(MaintenanceEmployee * emp)            //puts maintenance employee to work in all spaces
{
    cargo->setReadyCheck(false);                    //back to false because they have become true from security check
    equips[0]->setReadyCheck(false);
    equips[1]->setReadyCheck(false);
    equips[2]->setReadyCheck(false);



    if (emp->getWorkOn())
    {
        cout << "Employee already working" << endl;
        return false;
    }

    cout << "Maintenance Employee working:" << endl;
    process = emp;

    if (!cargo->isReadyCheck())
    {
        emp->setWorkOn(true);
        cout << "Checking Cargo Bay" << endl;
        emp->Report("Cargo Bay");

        cout << "Checking Cargo Bay's Equipment Compartment" << endl;
        emp->Report("Cargo Bay's Equipment Compartment");

        cargo->setReadyCheck(true);
        emp->setWorkOn(false);
    }

    int i;
    for (i=0; i<3; i++)
    {
        if (!equips[i]->isReadyCheck())
        {
            emp->setWorkOn(true);
            cout << "Checking Equipment Compartment" << endl;
            emp->Report("Equipment Compartment");
            equips[i]->setReadyCheck(true);
            emp->setWorkOn(false);
        }
    }

    process = nullptr;
    return cargo->isReadyCheck() && equips[0]->isReadyCheck() && equips[1]->isReadyCheck() && equips[2]->isReadyCheck();
}


bool Plane::CleaningCheck(CleaningEmployee * emp)               //puts cleaning employee to work in all spaces
{
    cargo->setReadyCheck(false);

    if (emp->getWorkOn())
    {
        cout << "Employee already working" << endl;
        return false;
    }

    cout << "Cleaning Employee working:" << endl;
    process = emp;

    if (!cargo->isReadyCheck())
    {
        emp->setWorkOn(true);
        cout << "Checking Cargo Bay" << endl;
        emp->Report("Cargo Bay");

        cout << "Checking Cargo Bay's Equipment Compartment" << endl;
        emp->Report("Cargo Bay's Equipment Compartment");

        cargo->setReadyCheck(true);
        emp->setWorkOn(false);
    }

    process = nullptr;
    return cargo->isReadyCheck() && spaces->CheckPassengerCompartments(emp);
}


int Plane::CalculatePassengerSpaces(int cap)
{
    return (rand()%5 + 1)*cap/100;                  //random number depending on capacity
}


Plane::~Plane()
{
    delete(process);
    delete(cargo);

    int i;
    for (i=0; i<3; i++)
    {
        delete equips[i];
    }
    delete spaces;

    cout << "Plane to be destroyed!" << endl;
}


//getters
const string &Plane::getDescr() const
{
    return descr;
}


const string &Plane::getTitle() const
{
    return title;
}


int Plane::getCapacity() const
{
    return capacity;
}


Employee *Plane::getProcess() const
{
    return process;
}


CargoBay *Plane::getCargo() const
{
    return cargo;
}


EquipmentCompartment *const *Plane::getEquips() const
{
    return equips;
}


int Plane::getN() const
{
    return n;
}


list *Plane::getSpaces() const
{
    return spaces;
}