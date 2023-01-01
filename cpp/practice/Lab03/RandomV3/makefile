CC = g++

main: main.o Random.o
	$(CC) -o main.exe main.o Random.o

main.o: main.cpp Random.cpp
	$(CC) -c main.cpp Random.cpp -I.

Random.o: Random.cpp
	$(CC) -c Random.cpp -I.

clean:
	rm -f *.o *.exe