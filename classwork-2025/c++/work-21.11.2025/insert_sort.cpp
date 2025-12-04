#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>

void insert_sort(int arr[], int len);
void printArr(int arr[], int len);
void fillrand(int arr[],int len);

int main()
{
    
    const int len{100000};
    int arr[len]{};
    fillrand(arr,len);

    std::cout << "Unsorted: ";
    printArr(arr,len);

    insert_sort(arr,len);

    std::cout << "Sorted: ";
    printArr(arr,len);
}

void printArr(int arr[],int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    } 
    std::cout << "\n";
}

void insert_sort(int arr[], int len)
{
    int t{arr[0]};
    arr[0] = std::numeric_limits<int>::min();

   for (int i{1}; i < len; i++){
    for (int j{}; arr[j] < arr[j-1] ;j--){
        int tmp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j]=tmp;

    }
   }
   int i{1};
   for (; t > arr[i];i++){
    arr[i-1]=arr[i];
   }
   arr[i-1] = t;
    
    
}

void fillrand(int arr[],int len){
    std::srand(std::time(nullptr));
    for (int i{};i < len;i++){
        arr[i]=rand();
    }
}