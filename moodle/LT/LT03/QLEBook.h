#ifndef QLEBOOK_H
#define QLEBOOK_H

#include "CEbook.h"

class QLEBook {
    private:
        CEbook *ebook;
        int max;
        int n;
    public:
        // constructors
        QLEBook();

        // destructor
        ~QLEBook();

        // copy constructor
        QLEBook(const QLEBook&);

        // operator =
        QLEBook& operator=(const QLEBook&);


        // other methods
        // 1. Sắp xếp danh sách giảm dần theo giá bán, xuất ra output1.txt
        void sortPrice ();

        // 2. Thống kê các sách có ISBN  3 số cuối là 730 , xuất ra output2.txt
        void stat ();

        // 3. Sắp xếp các sách theo thứ tự ngày sản xuất tăng dần, xuất ra output3.txt
        void sortDate ();
        // input/output
        friend ifstream& operator>>(ifstream&, QLEBook&);
        friend ofstream& operator<<(ofstream&, QLEBook&);
};

#endif