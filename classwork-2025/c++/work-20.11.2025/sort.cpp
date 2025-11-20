#include <iostream>

void sort(int arr[], int len);
void printArr(int arr[], int len);

int main()
{
    const int len{5};
    int arr[len]{3,5,76,12,6};

    std::cout << 

}

void sort(int arr[], int len, bool inc = true)
{
    for(int i{}; i < len; i++)
    {
        int inmin{i};
        printArr(arr,len);
        for(int j{i}; j < len; j++)
        {
            if (inc){
                if (arr[j] < arr[inmin]) inmin = j;
            }
            else{
                if (arr[j] > arr[inmin]) inmin = j;
            }
        }

        int tmp{arr[i]};
        arr[i] = arr[inmin];
        arr[inmin] = tmp;
    }
}

void printArr(int arr[],int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}