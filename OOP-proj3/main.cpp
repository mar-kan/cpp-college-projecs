#include <iostream>
#include <string>
#include <time.h>
#include "CleaningEmployee.h"
#include "MaintenanceEmployee.h"
#include "SecurityEmployee.h"
#include "Plane.h"
#include "clone_encrypt_and_print.h"
using namespace std;

int main()
{
    srand(time(0));

    Plane airplane("this is the plane", "Boeing", 200);
    Object * pl = &airplane;


    SecurityEmployee sec("George");
    Object * s = &sec;

    MaintenanceEmployee maint("Peter");
    Object * m = &maint;

    CleaningEmployee clean("Joe");
    Object * c = &clean;

    bool ok;
    ok = airplane.SecurityCheck(&sec);
    ok = ok && airplane.MaintenanceCheck(&maint);
    ok = ok && airplane.CleaningCheck(&clean);

    if (airplane.Ready() && ok)
        cout << "Plane ready to take off!" << endl;
    else
        cout << "Plane not ready" << endl;

    cout << endl;
    clone_encrypt_and_print(pl);
    cout << endl;

    return 0;
}
