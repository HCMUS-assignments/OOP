CC = g++

main: main.o Random.o Fraction.o
	$(CC) -o main.exe main.o Random.o Fraction.o

main.o: main.cpp Random.cpp Fraction.cpp
	$(CC) -c main.cpp Random.cpp Fraction.cpp -I.

Random.o: Random.cpp 
	$(CC) -c Random.cpp -I.

Fraction.o: Fraction.cpp
	$(CC) -c Fraction.cpp -I.

clean:
	rm -f *.o *.exe