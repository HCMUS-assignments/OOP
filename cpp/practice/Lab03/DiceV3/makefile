CC = g++

main: main.o Dice.o Random.o
	$(CC) -o main.exe main.o Random.o Dice.o

main.o: main.cpp Random.cpp
	$(CC) -c main.cpp Random.cpp -I.

Dice.o: Dice.cpp Random.cpp
	$(CC) -c Dice.cpp Random.cpp -I.

Random.o: Random.cpp
	$(CC) -c Random.cpp -I.

clean:
	rm -f *.o *.exe