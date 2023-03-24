#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class MyIntArray {
    private:
        int *pArr;
        int size;

    public:
        // default constructor
        MyIntArray();

        // parameter constructors: using input items of array
        MyIntArray(int sz);

        // destructor
        ~MyIntArray();

        // overloading [] operator to access elements in array
        int& operator [] (int);

        // copy constructor
        MyIntArray(const MyIntArray &);

        // assignment operator overloading
        MyIntArray& operator = (const MyIntArray&);

        // xuat mang
        void print();
};

#endif

// define methods
MyIntArray::MyIntArray() {
    pArr = NULL;
    size = 0;
}

MyIntArray::MyIntArray(int sz) {
    size = sz;
    pArr = new int[size];
    if (pArr == NULL) {
        cerr << "\n Khong du bo nho ...\n";
    }
    for (int i = 0; i < size; i++) {
        pArr[i] = 0;
    }
}

MyIntArray::~MyIntArray () {
    if (pArr != NULL) {
        delete [] pArr;
    }
    pArr = NULL;
    size = 0;
}

// overloading [] operator to access elements in array
int& MyIntArray::operator [] (int i) {
    return pArr[i];
}

// copy constructor
MyIntArray::MyIntArray (const MyIntArray& src) {
    size = src.size;
    pArr = new int[size];
    if (pArr == NULL) {
        cerr << "\nKhong du bo nho ...\n";
    }
    for (int i = 0; i < size; i++) {
        pArr[i] = src.pArr[i];
    }
}

// assignment operator overloading
MyIntArray& MyIntArray::operator=(const MyIntArray& src) {
    if (this == &src) {
        return *this;
    }
    if (pArr != NULL) {
        delete[] pArr;
        pArr = NULL;
    }

    size = src.size;
    pArr = new int[size];
    for (int i = 0; i < size; i++) {
        pArr[i] = src.pArr[i];
    }
}

// xuat mang
void MyIntArray::print() {
    for (int i = 0; i < size; i++) {
        cout << pArr[i] << " ";
    }
}

int main() {
    MyIntArray a(5);
    cout << "a[4] : " << a[4] << endl;
    MyIntArray b(a);
    cout << "Array a: " ;
    a.print();
    cout << "\nArray b: " ;
    b.print();
    MyIntArray c = a;
    cout << "\nArray c: ";
    c.print();
    return 225;

}

