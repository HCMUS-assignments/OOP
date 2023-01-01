CC = g++
main: main.o Fraction.o
	$(CC) -o main.exe main.o Fraction.o
main.o: main.cpp Fraction.hpp
	$(CC) -c main.cpp -I.
Fraction.o: Fraction.cpp Fraction.hpp
	$(CC) -c Fraction.cpp -I.
clean:
	rm -f *.o *.exe