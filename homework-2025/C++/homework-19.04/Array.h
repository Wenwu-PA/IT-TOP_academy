#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t n = 0);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    size_t getSize() const;
    void print() const;
};

#include "Array.cpp"

#endif