CC = g++

main: main.o Date.o
	$(CC) -o main.exe main.o Date.o

main.o: main.cpp Date.hpp
	$(CC) -c main.cpp -I.

Date.o: Date.cpp Date.hpp
	$(CC) -c Date.cpp -I.

clean:
	rm -f *.o *.exe