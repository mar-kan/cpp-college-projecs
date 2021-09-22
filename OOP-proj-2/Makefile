CC=g++
CFLAGS=-Wall -std=c++11 -O3 -g3 -pg -std=c++0x

school: main.o Class.o Corridor.o Floor.o utilities.o SchoolBuilding.o Stair.o Student.o Teacher.o  Room.o Person.o
	$(CC) -o school main.o Class.o Corridor.o Floor.o utilities.o SchoolBuilding.o Stair.o Student.o Teacher.o Room.o Person.o $(CFLAGS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Class.o: Class.cpp
	$(CC) $(CFLAGS) -c Class.cpp

Corridor.o: Corridor.cpp
	$(CC) $(CFLAGS) -c Corridor.cpp

Floor.o: Floor.cpp
	$(CC) $(CFLAGS) -c Floor.cpp

Person.o: Person.cpp
	$(CC) $(CFLAGS) -c Person.cpp

Room.o: Room.cpp
	$(CC) $(CFLAGS) -c Room.cpp

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

.PHONY: clean

clean:
	rm -f school *.o