#include <cassert>
#include "SchoolBuilding.h"
#include "Teacher.h"
#include "utilities.h"
#include "SeniorStudent.h"
#include "JuniorStudent.h"


int main(int argc, char *argv[]) {

    srand(time(NULL));

    if (argc < 6)
    {
        cout << "Too few arguments" << endl;
        exit(-1);
    }
    //stores program arguments
    int cClass, Lj, Ls, Lt, N;

    assert(cClass = atoi(argv[1]));
    assert(Lj = atoi(argv[2]));
    assert(Ls = atoi(argv[3]));
    assert(Lt = atoi(argv[4]));
    assert(N = atoi(argv[5]));

    /** creating school **/
    auto * school = new SchoolBuilding(cClass);                   //creates school building

    int student_count = cClass*20;

    /** creating students **/
    Student *outStudents[student_count]; //array that contains all students that are outside the school
    for (int i=0; i<student_count; i++)
    {
        if (i < student_count / 2)
            outStudents[i] = new SeniorStudent(generateRandomName(), rand()%3+1, rand()%3+4, Ls);   //creates new senior student with random name and random floor and class numbers (senior classes have numbers that end with [4,6])
        else
            outStudents[i] = new JuniorStudent(generateRandomName(), rand()%3+1, rand()%3+1, Lj);   //creates new junior student with random name and random floor and class numbers (junior classes have numbers that end with [1,3]
    }

    /** creating teachers **/
    int teach_count=0;
    Teacher*teachers[6 * 3];    //array that contains all teachers (their number is equal to num of classrooms)
    for (int i=0; i<3; i++)     //in each floor
    {
        for (int j=0; j<6; j++) //and each classroom
        {
            teachers[teach_count] = new Teacher(generateRandomName(), i+1, j+1, Lt); //adds one teacher with random name
            school->getFloorByNum(i+1)->getClassByNum((i+1)*10+j+1)->setTeacher(teachers[teach_count++]);    //sets him as him classroom's teacher
        }
    }

    /** all students enter the schoolyard in random order **/
    while (student_count>0)    //while there are students outside
    {
        //a random student enters school
        int pos=rand()%student_count;
        school->enter(outStudents[pos]);

        //removes student from array
        for (int i=pos; i<student_count-1; i++) //fixes rest of array so there are no gaps
            outStudents[i] = outStudents[i+1];

        student_count--;  //decreases number of students outside
    }

    /** all students exit schoolyard and enter stairs in random order **/
    while (school->getYard()->getStudentCount()>0)  //while there are people in yard
    {
        //gets random student position
        int pos=rand()%school->getYard()->getStudentCount();
        //exits schoolyard and enters stairs
        school->getStair()->enter(school->getYard()->exit(pos));
    }

    //for every floor fills corridor until stairs have students or there are no more students for this floor
    for (int floor=0; floor<3; floor++)
    {
        /** all students that go on each floor exit stairs and enter each floor's corridor **/
        while (school->getStair()->getStudentCount()>0)  //while there are students in stairs
        {
            //gets position of a student that goes to this floor
            int pos = school->getStair()->getStudentPosForFloor(floor+1);
            if (pos < 0)
                break;  //no more students for this floor

            //exits stairs and enters floor (its corridor)
            school->getFloorByNum(floor+1)->enter(school->getStair()->exit(pos));
        }

        for (int classe=0; classe<6; classe++)
        {
            /** students exit corridors and enter their classes until they are full **/
            while (school->getFloorByNum(floor+1)->getCorridor()->getStudentCount() && !school->getFloorByNum(floor+1)->getClassByNum((floor+1)*10+classe+1)->isFull())  //while there is room in classroom and people in floor corridor
            {
                //gets position of a student that goes to this classroom
                int pos = school->getFloorByNum(floor+1)->getCorridor()->getStudentPosFromClass((floor+1)*10+classe+1);
                if (pos < 0)
                    break;  //no more students for this floor

                //checks if classroom is full
                if (school->getFloorByNum(floor+1)->getClassByNum((floor+1)*10+classe+1)->isFull())
                    break;

                //exits corridor and enters classroom
                school->getFloorByNum(floor+1)->getClassByNum((floor+1)*10+classe+1)->enter(school->getFloorByNum(floor+1)->getCorridor()->exit(pos));
            }
        }
    }

    /**all teachers are placed in their classrooms **/
    for (int i=0; i<teach_count; i++)
        teachers[i]->place();   //places teacher

    /**operate**/
    for (int i=0; i<N; i++)
        school->operate();

    /** prints school **/
    school->print();

    delete school;
    exit(0);
}