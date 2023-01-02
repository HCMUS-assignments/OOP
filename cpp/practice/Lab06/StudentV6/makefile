CC = g++
main : main.o Student.o
	$(CC) -o main.exe main.o Student.o

main.o : main.cpp Student.hpp
	$(CC) -c main.cpp -I.

Student.o : Student.cpp Student.hpp
	$(CC) -c Student.cpp -I.

clean :
	rm *.o *.exe