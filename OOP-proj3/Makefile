Airplane: main.o Object.o CargoBay.o Employee.o MaintenanceEmployee.o SecurityEmployee.o CleaningEmployee.o EquipmentCompartment.o PassengerCompartment.o PlaneComponent.o PrivateCompartment.o String.o clone_encrypt_and_print.o Plane.o list.o

	g++ -o airplane main.o Object.o CargoBay.o Employee.o MaintenanceEmployee.o SecurityEmployee.o CleaningEmployee.o EquipmentCompartment.o PassengerCompartment.o PlaneComponent.o PrivateCompartment.o String.o clone_encrypt_and_print.o Plane.o list.o

main.o: main.cpp
	g++ -g -c  main.cpp

Object.o: Object.cpp Object.h
	g++ -g -c Object.cpp

CargoBay.o: CargoBay.cpp CargoBay.h
	g++ -g -c CargoBay.cpp

Employee.o: Employee.cpp Employee.h
	g++ -g -c Employee.cpp

MaintenanceEmployee.o: MaintenanceEmployee.cpp MaintenanceEmployee.h
	g++ -g -c MaintenanceEmployee.cpp

SecurityEmployee.o: SecurityEmployee.cpp SecurityEmployee.h
	g++ -g -c SecurityEmployee.cpp

CleaningEmployee.o: CleaningEmployee.cpp CleaningEmployee.h
	g++ -g -c CleaningEmployee.cpp

EquipmentCompartment.o: EquipmentCompartment.cpp EquipmentCompartment.h
	g++ -g -c EquipmentCompartment.cpp

PassengerCompartment.o: PassengerCompartment.cpp PassengerCompartment.h
	g++ -g -c PassengerCompartment.cpp

PlaneComponent.o: PlaneComponent.cpp PlaneComponent.h
	g++ -g -c PlaneComponent.cpp

PrivateCompartment.o: PrivateCompartment.cpp PrivateCompartment.h
	g++ -g -c PrivateCompartment.cpp

String.o: String.cpp String.h
	g++ -g -c String.cpp

clone_encrypt_and_print.o: clone_encrypt_and_print.cpp clone_encrypt_and_print.h
	g++ -g -c clone_encrypt_and_print.cpp

Plane.o: Plane.cpp Plane.h
	g++ -g -c Plane.cpp

list.o: list.cpp list.h
	g++ -g -c list.cpp

clean:
	rm *.o airplane
