#ifndef QLPHIM_H
#define QLPHIM_H

#include "Phim.h"
#include "Vector.h"

class QLPhim {
    private:
        // using vector template on Bai 1
        Vector<Phim> _dsPhim;

    public:
        // methods
        QLPhim();
        ~QLPhim();

        // 1. Giả sử danh sách phim đã được sắp xếp tăng dần theo năm sản xuất.
        // Hãy viết phương thức thêm vào 1 phim mà vẫn duy trì thứ tự sau khi thêm
        void addPhim(Phim phim);

        // 2. Ghi danh sách phim vào tập tin với tên file (ds_phim.dat)
        void writeToFile();


        // 3. Đọc danh sách phim từ file (ds_phim.dat)
        void readFromFile();

        // 4. Xóa các phim có nhà sản xuất 'HBO' , cập nhật lại danh sách phim trên file
        void deleteHBO();

};

#endif