CC = g++

main: main.o Rectangle.o Point.o
	$(CC) -o main.exe main.o Rectangle.o Point.o

main.o: main.cpp Rectangle.cpp
	$(CC) -c main.cpp Rectangle.cpp -I.

Rectangle.o: Rectangle.cpp Point.cpp
	$(CC) -c Rectangle.cpp Point.cpp -I.

Point.o: Point.cpp
	$(CC) -c Point.cpp -I.

clean:
	rm -f *.o *.exe

