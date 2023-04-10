#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
    T *ptr;
    int capacity;
    int sz;

public:
    // constructors
    Vector();
    Vector(int cap);

    // destructor
    ~Vector();

    // methods
    T& operator[](int n);

    // expand extra memory
    void reserve(int newalloc);

    // input output
    void push(const T& element);
    void print();
};
#endif


// define
template <typename T>
Vector<T>::Vector()
{
    ptr = nullptr;
    capacity = 0;
    sz = 0;
}

template <typename T>
Vector<T>::Vector(int cap)
{
    ptr = new T[cap];
    capacity = cap;
    sz = 0;
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] ptr;
}

template <typename T>
T& Vector<T>::operator[](int n)
{
    return ptr[n];
}

template <typename T>
void Vector<T>::reserve(int newalloc)
{
    if (newalloc <= capacity)
        return;

    T *p = new T[newalloc];
    for (int i = 0; i < sz; i++)
        p[i] = ptr[i];

    delete[] ptr;
    ptr = p;
    capacity = newalloc;
}


template <typename T>
void Vector<T>::push(const T& element)
{
    if (capacity == 0)
        reserve(8);
    else if (sz == capacity)
        reserve(2 * capacity);

    ptr[sz] = element;
    sz++;
}

template <typename T>
void Vector<T>::print()
{
    for (int i = 0; i < sz; i++)
        cout << ptr[i] << " ";
    cout << endl;
}
