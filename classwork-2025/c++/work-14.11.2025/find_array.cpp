#include <iostream>

int find_arr(int arr[],int len,int value){

    int index{-1};
    for (int i{};i<len;i++){
        if (arr[i]==value){
            index == i;
            return index;
        }
    }
    return index;
    
}

int main(){
    const int len{5};
    int arr[len]{23,0,-76,402,7};

    std::cout << "input ";
    int value{};
    std::cin >> value;

    int result {find_arr(arr,len,value)};
    if (result > 0){
        std::cout << "error";
    }
    else{
        std::cout << result;
    }

    return 0;
}