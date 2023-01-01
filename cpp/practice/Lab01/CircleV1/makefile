CC = g++

main: main.o Circle.o
	$(CC) -o main.exe main.o Circle.o

main.o: main.cpp Circle.hpp Point.hpp
	$(CC) -c main.cpp -I.

Circle.o: Circle.cpp Circle.hpp Point.hpp
	$(CC) -c Circle.cpp -I.

clean:
	rm -f *.o *.exe
	

