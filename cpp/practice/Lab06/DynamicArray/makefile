CC = g++
main: main.o DynamicArray.o
	$(CC) -o main.exe main.o DynamicArray.o

main.o: main.cpp DynamicArray.hpp
	$(CC) -c main.cpp -I.

DynamicArray.o: DynamicArray.cpp DynamicArray.hpp
	$(CC) -c DynamicArray.cpp -I.

clean:
	rm -f *.o *.exe