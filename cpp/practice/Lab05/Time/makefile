CC = g++

main: main.o Time.o
	$(CC) -o main.exe main.o Time.o

main.o: main.cpp Time.hpp
	$(CC) -c main.cpp -I.

Time.o: Time.cpp Time.hpp
	$(CC) -c Time.cpp -I.

clean:
	rm -f *.o *.exe