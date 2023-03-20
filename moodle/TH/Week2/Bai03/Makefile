CC = g++

main: SinhVien.o QLSinhVien.o
	$(CC) -o main.exe SinhVien.o QLSinhVien.o

QLSinhVien.o: SinhVien.o QLSinhVien.cpp
	$(CC) -c QLSinhVien.cpp SinhVien.o -I.

SinhVien.o: SinhVien.cpp
	$(CC) -c SinhVien.cpp -I.

	
clean:
	rm -f *.o *.exe
	

