#include <iostream>

void select_sort(int arr[],int len){

    for (int i{}; i < len; i++){
        int inmin{i};
        for (int j{i};j < len;j++){
            if (arr[j]<arr[inmin])
            {
                inmin = j;
            }
        int temp{arr[i]};
        arr[i] = arr[inmin];
        arr[inmin] = temp;
        }
    }
}

int main(){

   

    return 0;
}