#include <iostream>
int& rmax(int n,int d[]){
    int im{0};
    for (int i{1}; i<n;i++){
        if(d[im]<d[i]){
            im = i;
        }
    }
    return d[im];
}

void printArr(int* arr,int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main(){

    const int len{5};
    int arr[len]{1,2,3,4,5};
    printArr(arr,len);
    rmax(len,arr) = 0;
    printArr(arr,len);

    

    return 0;

}