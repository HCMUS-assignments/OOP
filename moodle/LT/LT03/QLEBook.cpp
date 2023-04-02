#include "QLEBook.h"

// constructors
QLEBook::QLEBook()
{
    ebook = NULL;
    max = 100;
    n = 0;
}

// destructor
QLEBook::~QLEBook()
{
    if (ebook != NULL)
        delete[] ebook;
}

// copy constructor
QLEBook::QLEBook(const QLEBook &another)
{
    ebook = new CEbook[another.max];
    max = another.max;
    n = another.n;
    for (int i = 0; i < n; i++)
        ebook[i] = another.ebook[i];
}

QLEBook& QLEBook::operator=(const QLEBook &another) {
    if (this != &another) {
        ebook = new CEbook[another.max];
        max = another.max;
        n = another.n;
        for (int i = 0; i < n; i++)
            ebook[i] = another.ebook[i];
    }
    return *this;

}

// other methods
// 1. Sắp xếp danh sách giảm dần theo giá bán, xuất ra output1.txt
void QLEBook::sortPrice()
{
    for (int i = 0; i < n - 1 ; i++)
        for (int j = i + 1; j < n; j++)
            if (ebook[i] < ebook[j]) {
                CEbook temp = ebook[i];
                ebook[i] = ebook[j];
                ebook[j] = temp;
            }
    ofstream fout("output1.txt");
    if (fout.fail()) {
        cout << "Can't open file output1.txt" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
        fout << ebook[i].getISBN() << " " << ebook[i].getPrice() << endl;
    fout.close();
}

// 2. Thống kê các sách có ISBN  3 số cuối là 730 , xuất ra output2.txt
void QLEBook::stat()
{
    ofstream fout("output2.txt");
    if (fout.fail()) {
        cout << "Can't open file output2.txt" << endl;
        return;
    }



}

// 3. Sắp xếp các sách theo thứ tự ngày sản xuất tăng dần, xuất ra output3.txt
void QLEBook::sortDate()
{
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            
        }
        
    }
}
// input/output
ifstream &operator>>(ifstream &fin, QLEBook &src)
{

    while (!fin.eof()) {
        if (src.n == src.max) {
            CEbook *temp = new CEbook[src.max + 100];
            for (int i = 0; i < src.n; i++)
                temp[i] = src.ebook[i];
            delete[] src.ebook;
            src.ebook = temp;
            src.max += 100;
        }
            
        fin >> src.ebook[src.n];
        src.n++;
    }
    return fin;
}
ofstream &operator<<(ofstream &fout, QLEBook &src)
{

    for (int i = 0; i < src.n; i++)
        fout << src.ebook[i];
    return fout;
}
