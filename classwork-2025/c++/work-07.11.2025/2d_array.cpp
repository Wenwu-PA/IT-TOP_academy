#include <iostream>

const int h{4};
const int w{3};

void double_array(int arr[h][w],int w, int h){

    for(int i{};i < h;i++){
        for (int j{}; j<w;j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

}

void main(){
    
    int arr[h][w]{
        {1,2,3},
        {1,2,3},
        {1,2,3},
        {1,2,3}
        };
    double_array(arr,w,h);

}


