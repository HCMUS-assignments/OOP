#include "Vector.h"

template <class T>
Vector<T>::Vector() {
    ptr = NULL;
    capacity = 0;
    sz = 0;
}

template <class T>
Vector<T>::Vector(int cap) {
    capacity = cap;
    sz = 0;
    ptr = new T[capacity];
}

template <class T>
Vector<T>::~Vector() {
    delete[] ptr;
}

template <class T>
T& Vector<T>::operator[] (int index) {
    return ptr[index];
}

template <class T>
void Vector<T>::reserve(int newAlloc) {
    if (newAlloc <= capacity) return;
    T *temp = new T[newAlloc];
    for (int i = 0; i < sz; i++) {
        temp[i] = ptr[i];
    }
    delete [] ptr;
    ptr = temp;
    capacity = newAlloc;
}

template <class T>
void Vector<T>::push(const T& element) {
    if (sz == capacity) {
        if (capacity == 0) {
            reserve(10);
        } else {
            reserve(2 * capacity);
        }
    }
    ptr[sz] = element;
    sz++;

}

template <class T>
void Vector<T>::print() {
    for (int i = 0; i < sz; i++) {
        cout << ptr[i] << " ";
    }
}

#include "Phim.h"
template class Vector<Phim*>;
