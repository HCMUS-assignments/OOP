
CC = g++

main: main.o Student.o Person.o
	$(CC) -o main.exe main.o Student.o Person.o

main.o: main.cpp Student.cpp Person.cpp
	$(CC) -c main.cpp -I.

Student.o:  Student.cpp 
	$(CC) -c Student.cpp  -I.

Person.o: Person.cpp 
	$(CC) -c Person.cpp -I.



clean:
	rm -f *.o *.exe
	

