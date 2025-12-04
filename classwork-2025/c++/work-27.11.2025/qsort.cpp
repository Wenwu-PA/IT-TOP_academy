#include <iostream>
#include <stdlib.h>
#include <time.h>

template <class T>
void qsort(T a[], long N){
    long i{0}, j{N-1};
    T temp;
    T p{a[N/2]};

    do{
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }while (i <=j );

    if (j > 0) qsort(a,j+1);
    if (N > i) qsort(a+i,N-i);
}

void printArr(int arr[],int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    const int len{6};
    int arr[len]{6,1,2,3,4,5};

    std::cout << "Unsorted: ";
    printArr(arr,len);

    qsort(arr,len);

    std::cout << "Sorted: ";
    printArr(arr,len);
}