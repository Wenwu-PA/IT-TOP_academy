#include <iostream>

void shake_sort(int arr[], int len);
void printArr(int arr[], int len);

int main()
{
    const int len{6};
    int arr[len]{7,6,5,4,3,34};

    std::cout << "Unsorted: ";
    printArr(arr,len);

    shake_sort(arr,len);

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

void shake_sort(int arr[], int len)
{
    int j{};
    int k{len-1};
    int lb{1};
    int rb{len-1};
    int x{};

    do{
        
        for(j = rb; j > 0;j--){
            if(arr[j-1] > arr[j]){
                x = arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=x;
                k=j;
            }
        }
        lb = k + 1;
        printArr(arr,len);
        for(j = 1; j <= rb;j++){
            if(arr[j-1] > arr[j]){
                x = arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=x;
                k=j;
            }
        }
        rb = k - 1;
        printArr(arr,len);
    } while(lb < rb);
    
    
}