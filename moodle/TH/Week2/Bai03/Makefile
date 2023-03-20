CC = g++

main: main.o QLSinhVien.o SinhVien.o
	$(CC) -o main.exe main.o QLSinhVien.o SinhVien.o

main.o: main.cpp QLSinhVien.h SinhVien.h
	$(CC) -c main.cpp -I.

QLSinhVien.o: QLSinhVien.cpp SinhVien.h
	$(CC) -c QLSinhVien.cpp -I.

SinhVien.o: SinhVien.cpp 
	$(CC) -c SinhVien.cpp -I.



clean:
	rm -f *.o *.exe
	

