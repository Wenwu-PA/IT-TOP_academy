#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.h"
#include <iostream>

template <typename T>
Array<T>::Array(size_t n) : size(n) {
    data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : size(other.size) {
    data = new T[size];
    for (size_t i = 0; i < size; ++i)
        data[i] = other.data[i];
}

template <typename T>
Array<T>::Array(Array&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size) {
        std::cerr << "Array index out of bounds!" << std::endl;
        static T dummy = T();
        return dummy;
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= size) {
        std::cerr << "Array index out of bounds!" << std::endl;
        static const T dummy = T();
        return dummy;
    }
    return data[index];
}

template <typename T>
size_t Array<T>::getSize() const {
    return size;
}

template <typename T>
void Array<T>::print() const {
    for (size_t i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

#endif