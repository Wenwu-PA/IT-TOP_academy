#include <iostream>

int main(){
    const int len{5};

    int arr[len]{1,0,-5,34,6};

    int * ptr{&arr[0]};

    // std::cout << ptr << " " << "\n" <<  *ptr << "\n";

    // ptr = &arr[1];

    // std::cout << ptr << " " << "\n" <<  *ptr << "\n";

    // ptr = ptr + 1;

    // std::cout << ptr << " " << "\n" <<  *ptr << "\n";

    for (int i{}; i < len; i++){
        // std::cout << *ptr << ' ';
        // ptr++;

        std::cout << ptr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}