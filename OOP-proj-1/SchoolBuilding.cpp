#include "SchoolBuilding.h"
#include "utilities.h"


SchoolBuilding::SchoolBuilding(int cClass, int cYard, int cStair, int cCor)    //constructor of school building
{                                   //initializes 3 floors, yard and stair
    cout << "A New School has been created!" << endl;

    for (int i=0; i<3; i++)
        floors[i] = new Floor(i+1, cClass, cCor);  //i+1 represents floor num

    yard = new Yard(cYard);
    stair = new Stair(cStair);

    student_count = (int)random()%200 + 1+cClass+cYard+cStair+cCor;  //random number between [cSum, cSum+200]
    outStudents = new Student*[student_count]; //array that contains all students that are outside the school
}


SchoolBuilding::~SchoolBuilding()   //deletes all  compartments of school building
{
    cout << "A School to be destroyed!" << endl;

    for (auto & floor : floors)
        delete floor;

    delete stair;
    delete yard;

    for (int i=0; i<student_count; i++)
        delete outStudents[i];

    delete[] outStudents;
}


void SchoolBuilding::enter()    //students and teachers are created and enter school
{
    int teach_count=6*3;    //for 3 floors with 6 classrooms each

    /** creating students **/
    for (int i=0; i<student_count; i++)
        outStudents[i] = new Student(generateRandomName(), i%3+1, i%6+1);   //creates new student with random name and random floors and class numbers

    /** creating teachers **/
    int count=0;
    Teacher*teachers[6 * 3];    //array that contains all teachers (their number is equal to num of classrooms
    for (int i=0; i<3; i++)    //in each floor
    {
        for (int j=0; j<6; j++) //and each classroom
        {
            teachers[count] = new Teacher(generateRandomName(), i, j); //adds one teacher with random name
            floors[i]->getClassByNum((i+1)*10+j+1)->setTeacher(teachers[count++]);    //sets him as him classroom's teacher
        }
    }

    bool flag = true;
    while (student_count>0 && !yard->isFull() && flag) //fills all spaces until there are no people out or no one else can enter
    {
        flag = false;

        /** students enter schoolyard until it is full **/
        while (!yard->isFull() && student_count>0)    //while yard is not full and there are students outside
        {
            //a random student enters school
            int pos=(int)random()%student_count;

            cout << outStudents[pos]->getName() << " enters building!"<< endl;
            if (!yard->enter(outStudents[pos]))   //if a student cant enter, loop breaks
                break;

            //removes student from array
            for (int i=pos; i<student_count; i++) //fixes rest of array so there are no gaps
                outStudents[i] = outStudents[i+1];

            student_count--;  //decreases number of students outside

            flag = true;
        }

        /** students exit schoolyard and enter stairs until they are full **/
        while (!stair->isFull() && yard->getStudentCount()>0)  //while there is room in stairs and people in yard
        {
            //a random student exits schoolyard
            int pos=rand()%yard->getStudentCount();
            Student * student = yard->getStudentInPos(pos);
            yard->exit(student);

            //same student enters stairs
            if (!stair->enter(student))   //if a student cant enter, loop breaks
                break;

            flag = true;
        }

        //for every floor fills corridor until full and then all its classrooms
        for (int floor=0; floor<3; floor++)
        {
            /** students that go on each floor exit stairs and enter each floor's corridor until it is full **/
            while (!floors[floor]->getCorridor()->isFull())  //while there is room in corridor of each floor
            {
                //a student that goes to this floor exits the stairs
                Student * student = stair->getStudentFromFloor(floor+1);
                if (!student)   //no more students for this floor
                    break;

                //student exits stairs and enters floor's corridor
                stair->exit(student);
                if (!floors[floor]->getCorridor()->enter(student))   //if he didnt enter he remains in array outStudents
                    break;

                flag = true;
            }

            for (int classe=0; classe<6; classe++)
            {
                /** students exit corridors and enter their classes until they are full **/
                while (!floors[floor]->getClassByNum((floor+1)*10+classe+1)->isFull())  //while there is room in stairs
                {
                    //a student that goes to this class exits the corridor
                    Student * student = floors[floor]->getCorridor()->getStudentFromClass((floor+1)*10+classe+1);
                    if (!student)   //no more students for this class
                        break;

                    //student exits corridor and enters his classroom
                    floors[floor]->getCorridor()->exit(student);
                    if (!floors[floor]->getClassByNum((floor+1)*10+classe+1)->enter(student))
                        break;

                    flag = true;
                }
            }
        }

        /** teachers are placed in their classrooms with 25% chance in each iteration **/
        for (int i=0; i<teach_count; i++)
        {
            if (random()%4 != 0)  //25% chance to enter classroom
                continue;

            teachers[i]->place();   //places teacher
            teachers[i] = nullptr;  //removes him from teachers
            for (int j=i; j<teach_count; j++) //fixes rest of array so there are no gaps
            {
                teachers[j] = teachers[j+1];
            }
            teach_count--;
            i--; //continues in same position, with a different teacher
        }
    }
}


void SchoolBuilding::print()       //prints school building as requested
{
    cout << "School life consists of: "<< endl;
    yard->print();
    stair->print();

    for (auto & floor : floors)
        floor->print();
}