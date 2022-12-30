CC = g++
main: main.cpp Line.cpp Line.hpp Point.hpp
	$(CC) -o a.exe main.cpp Line.cpp -I.

Line: Line.cpp Line.hpp Point.hpp
	$(CC) -g -c Line.cpp -I.

clean:
	del *.exe
	del *.o
