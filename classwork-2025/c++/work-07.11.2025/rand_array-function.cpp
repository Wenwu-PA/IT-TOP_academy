#include <iostream>
#include <ctime>
#include <cstdlib>

int maxIdArr(int array[],int n){
    int index{};
    for(int i{1};i < n;i++){
        if (array[i] > array[index]){
            index = i;
        }
    }
    return index;
}

void change_arr(int arr[],int n){
    std::cout << "input num: ";
    std::cin >> arr [0];
}

void main(){
    const int num{10};
    int array[num]{};
    int rborder{};
    int lborder{};
    std::srand(std::time({}));
    
    std::cout << "Border: " << '\n';
    std::cin >> lborder >> rborder ;


    for (int i{0};i < num;i++){
    array[i] = std::rand() % (rborder - lborder + 1) + lborder;
    }
    
    for(int i{}; i < num; i++){
    std::cout << array[i] << " ";
    }
    std::cout << '\n';

    change_arr(array,num);

    for(int i{}; i < num; i++){
    std::cout << array[i] << " ";
    }
    std::cout << '\n';

     std::cout << "max id in array - " << maxIdArr(array,num);
}