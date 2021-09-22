CC=g++
CFLAGS=-Wall -std=c++11 -O3 -g3 -pg -std=c++0x

school: main.o Classroom.o Corridor.o Floor.o utilities.o SchoolBuilding.o Stair.o Student.o Teacher.o Yard.o
	$(CC) -o school main.o Classroom.o Corridor.o Floor.o utilities.o SchoolBuilding.o Stair.o Student.o Teacher.o Yard.o $(CFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Classroom.o: Classroom.cpp
	$(CC) $(CFLAGS) -c Classroom.cpp

Corridor.o: Corridor.cpp
	$(CC) $(CFLAGS) -c Corridor.cpp

Floor.o: Floor.cpp
	$(CC) $(CFLAGS) -c Floor.cpp

utilities.o: utilities.cpp
	$(CC) $(CFLAGS) -c utilities.cpp

SchoolBuilding.o: SchoolBuilding.cpp
	$(CC) $(CFLAGS) -c SchoolBuilding.cpp

Stair.o: Stair.cpp
	$(CC) $(CFLAGS) -c Stair.cpp

Student.o: Student.cpp
	$(CC) $(CFLAGS) -c Student.cpp

Teacher.o: Teacher.cpp
	$(CC) $(CFLAGS) -c Teacher.cpp

Yard.o: Yard.cpp
	$(CC) $(CFLAGS) -c Yard.cpp

.PHONY: clean

clean:
	rm -f school *.o