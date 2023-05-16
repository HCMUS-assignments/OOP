CC = g++

main: main.o NhanVien.o NVSanXuat.o NVCongNhat.o CongTy.o
	$(CC) -o main.exe main.o NhanVien.o NVSanXuat.o NVCongNhat.o CongTy.o

main.o: main.cpp
	$(CC) -c main.cpp -I.

NhanVien.o: NhanVien.cpp
	$(CC) -c NhanVien.cpp -I.

NVSanXuat.o: NVSanXuat.cpp
	$(CC) -c NVSanXuat.cpp -I.

NVCongNhat.o: NVCongNhat.cpp
	$(CC) -c NVCongNhat.cpp -I.

CongTy.o: CongTy.cpp
	$(CC) -c CongTy.cpp -I.

clean:
	rm -f *.o *.exe