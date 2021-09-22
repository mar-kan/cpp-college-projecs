#include <cassert>
#include "SchoolBuilding.h"
#include "Teacher.h"
#include "utilities.h"


int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc < 5)
    {
        cout << "Too few arguments" << endl;
        exit(-1);
    }
    //store program arguments
    int cClass, cYard, cStair, cCor;

    assert(cClass = atoi(argv[1]));
    assert(cYard = atoi(argv[2]));
    assert(cStair = atoi(argv[3]));
    assert(cCor = atoi(argv[4]));

    /** creating school **/
    auto * school = new SchoolBuilding(cClass, cYard, cStair, cCor); //creates school building

    /** entering school **/
    school->enter();

    /** prints school **/
    school->print();

    delete school;
    exit(0);
}