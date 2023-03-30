CC = g++

main: main.o NhanVien.o NVSanXuat.o NVCongNhat.o
	$(CC) -o main.exe main.o NhanVien.o NVSanXuat.o NVCongNhat.o

main.o: main.cpp
	$(CC) -c main.cpp -I.

NhanVien.o: NhanVien.cpp
	$(CC) -c NhanVien.cpp -I.

NVSanXuat.o: NVSanXuat.cpp
	$(CC) -c NVSanXuat.cpp -I.

NVCongNhat.o: NVCongNhat.cpp
	$(CC) -c NVCongNhat.cpp -I.

clean:
	rm -f *.o *.exe