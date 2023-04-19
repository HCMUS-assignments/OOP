#include <iostream>
using namespace std;

/*
Cài đặt cấu trúc mảng 1 chiều (sử dụng template) với các chức năng sau:
- MyPush2 (thêm phần tử vào vị trí bất kỳ)
- MyPop2 (lấy phần tử lớn thứ 2 của mảng ra)
- MySwap (bỏ vào 2 index và hoán đổi 2 giá trị trong mảng với nhau)
- MyRo (loại bỏ các số âm khỏi mảng)
- MyRe (đảo ngược mảng lại từ cuối về đầu)

*/
#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array
{
private:
    T *list;
    int _max;
    int _size;

public:
    // constructor and destructor
    Array();
    ~Array();

    // methods
    // init array
    bool Init(int max);

    // thêm phần tử vào vị trí bất kì
    void MyPush2(T value, int pos);

    // lấy phần tử lớn thứ 2 của mảng ra
    T MyPop2();

    // bỏ vào 2 index và hoán đổi 2 giá trị trong mảng với nhau
    void MySwap(int index1, int index2);

    // loại bỏ các số âm khỏi mảng
    void MyRo();

    // đảo ngược mảng lại từ cuối về đầu
    void MyRe();

    // xuất mảng
    void print();
};

#endif

// define methods here
template <class T>
Array<T>::Array()
{
    list = NULL;
    _max = 0;
    _size = 0;
}

template <class T>
Array<T>::~Array()
{
    if (list != NULL)
    {
        delete[] list;
    }
}

template <class T>
bool Array<T>::Init(int max)
{
    list = new T[max];
    if (!list)
    {
        return false;
    }
    for (int i = 0; i < _max; i++) {
        list[i] = 0;
    }
    _max = max;
    _size = 0;
    return true;
}

template <class T>
void Array<T>::MyPush2(T value, int pos)
{
    if (pos > _max)
    {
        return;
    }
    list[pos - 1] = value;
    _size ++;
}

// lấy phần tử lớn thứ 2 của mảng ra
template <class T>
T Array<T>::MyPop2()
{
    int _max1 = list[0];
    int _max2 = list[0];
    for (int i = 1; i < _size; i ++) {
        if (_max1 < list[i]) {
            _max1 = list[i];
        } else {
            if (_max2 >= _max1) {
                _max2 = list[i];
            }
            if (_max2 < list[i]) {
                _max2 = list[i];
            }
        }
    }
    return _max2;
}

// bỏ vào 2 index và hoán đổi 2 giá trị trong mảng với nhau
template <class T>
void Array<T>::MySwap(int index1, int index2)
{
    T temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

// loại bỏ các số âm khỏi mảng
template <class T>
void Array<T>::MyRo()
{
    for (int i = 0; i < _size; i++) {
        if (list[i] < 0) {
            for (int j = i; j < _size-2; j++) {
                list[j] = list[j+1];
            }
        }
    }
}
// đảo ngược mảng lại từ cuối về đầu
template <class T>
void Array<T>::MyRe()
{
    T *temp = new T[_size];
    int d = 0;
    for (int i = _size - 1; i >= 0; i--) {
        temp[d++] = list[i];
    }
    delete[] list;
    list = temp;
}

template <class T>
void Array<T> :: print() {
    for (int i = 0; i < _size; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{

    Array<int> arr;
    arr.Init(22);
    arr.MyPush2(22, 9);
    arr.MyPush2(5, 7);
    arr.MyPush2(2003, 1);
    arr.MyPush2(-99, 13);
    arr.MyPush2(-17, 20);

    arr.print();

    cout << "Phan tu lon thu 2 : " <<  arr.MyPop2() << endl;

    cout << "\nDao nguoc mang tu cuoi ve dau: ";
    arr.MyRe();
    arr.print();

    cout << "\nLoai bo cac so am khoi mang: ";
    arr.MyRo();
    arr.print();

    cout << "Hoan doi 22 va 5 : " ;
    arr.MySwap(9, 7);
    arr.print();



    return 225;
}