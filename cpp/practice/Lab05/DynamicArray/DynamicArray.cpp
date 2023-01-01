#include "DynamicArray.hpp"

DynamicArray::DynamicArray() {
    _a = new int[DEFAULT_LEN];
    _len = 0;
    _max = DEFAULT_LEN;
}

DynamicArray::DynamicArray(int len) {
    if (len <= 0) {
        len = DEFAULT_LEN;
    }

    _a = new int[len];
    _len = 0;
    _max = len;
}

DynamicArray::~DynamicArray() {
    if (_a != nullptr) {
        delete[] _a;
        _a = nullptr;
    }
}


DynamicArray::DynamicArray(const DynamicArray& dynamicArray) {
    _len = dynamicArray._len;
    _max = dynamicArray._max;

    _a = new int[_max];
    for (int i = 0; i < _len; i++) {
        _a[i] = dynamicArray._a[i];
    }
}

void DynamicArray::PushBack(int value) {
    _a[_len] = value;
    _len++;
}

int DynamicArray::GetAt(int i) {
    return _a[i];
}

string DynamicArray::toString() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < _len; i++) {
        ss << _a[i];
        if (i < _len - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}