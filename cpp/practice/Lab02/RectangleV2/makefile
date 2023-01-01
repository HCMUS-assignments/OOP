CC = g++

main: main.o Rectangle.o
	$(CC) -o main.exe main.o Rectangle.o

main.o: main.cpp Rectangle.cpp Rectangle.hpp Point.hpp
	$(CC) -c main.cpp Rectangle.cpp -I.

Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	$(CC) -c Rectangle.cpp -I.

clean:
	rm -f *.o *.exe
	