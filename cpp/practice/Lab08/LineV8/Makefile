CC = g++
main: main.o Line.o 
	$(CC) -o main.exe main.o Line.o
main.o: main.cpp Line.cpp 
	$(CC) -c main.cpp -I.

Line.o: Line.cpp Point.hpp
	$(CC) -c Line.cpp -I.	

clean:
	rm *.exe
	rm *.o
