CC = g++

main : main.o Triangle.o
	$(CC) -o main.exe main.o Triangle.o

main.o : main.cpp Triangle.hpp Point.hpp
	$(CC) -c main.cpp -I.

Triangle.o : Triangle.cpp Triangle.hpp Point.hpp
	$(CC) -c Triangle.cpp -I.

clean :
	rm *.o *.exe
	
