CC = g++
main : main.o Line.o Point.o
	$(CC) -o main.exe main.o Line.o Point.o

main.o : main.cpp Line.cpp Point.cpp
	$(CC) -c main.cpp Line.cpp Point.cpp -I.

Line.o : Line.cpp Line.hpp Point.cpp Point.hpp
	$(CC) -c Line.cpp Point.cpp -I.

Point.o : Point.cpp Point.hpp
	$(CC) -c Point.cpp -I.

clean :
	rm *.o *.exe
