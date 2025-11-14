#include <iostream>

template <typename T> 
T double_array(T arr[][5],int hei,int len){
    T max{arr[0][0]};
    for (int i{};i<hei;i++){
        for(int j{};j<len;j++){
            if(max < arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int main(){
    
    const int len{5};
    const int hei{3};
    double arr[hei][len]{
    {23,42,13,3},
    {24,34.6,13,13},
    {23,4.2,1.3,2.3}};
    int arrInt[hei][len]{
    {23,42,13,3},
    {24,34,13,13},
    {23,4,1,2}};
    std::cout << double_array(arr,hei,len) << "\n";
    std::cout << double_array(arrInt,hei,len) << "\n";
    

    return 0;
}