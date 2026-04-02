#include <iostream>
#include "Array.h"

Array::Array(int s): size{s}, array{new int[size]} {}
Array::Array(const Array& arr): size{arr.size}, array{new int[size]}
{
    for(int i{}; i < size; i++)
        array[i] = arr[i];
}
Array::~Array()
{ delete[] array; }
int Array::len() const
{ return size; }
const Array& Array::operator=(const Array& arr)
{
    if(this == &arr)
        return *this;
    if(size != arr.size)
    { 
        delete[] array;   
        size = arr.size;
        array = new int[size];
    }
    for(int i{}; i < size; i++)
        array[i] = arr[i];
    return *this;
}

bool Array::operator==(const Array& arr) const{
    if(size != arr.size){
        return false;
    }
    for(int i{}; i < size; i++){
        if(array[i] != arr.array[i]){
            return false;
        }
    }
    return true;
}

int& Array::operator[](int i){
    if(i<0||i>= size){
        std::cout << "Index out of range\n";
        exit(i);
    }

    return array[i];
}
int Array::operator[](int i)const {
    if(i<0||i>= size){
        std::cout << "Index out of range\n";
        exit(i);
    }

    return array[i];
}

std::ostream& operator << (std::ostream& out, const Array& arr){
    for(int i{};i< arr.size;i++){
        out << arr.array[i] << " ";
    }
    return out;
}

std::istream& operator >> (std::istream& in, Array& arr ){
    for (int i{}; i < arr.size; i++){
        in >> arr.array[i];
    }
    return in;
}