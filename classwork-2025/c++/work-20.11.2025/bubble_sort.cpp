#include <iostream>

void bubble_sort(int arr[], int len,bool inc);
void printArr(int arr[], int len);

int main()
{
    const int len{6};
    int arr[len]{6,1,2,3,4,5};

    std::cout << "Unsorted: ";
    for(int i{}; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    bubble_sort(arr,len,true);

    std::cout << "Sorted: ";
    for(int i{}; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void printArr(int arr[],int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void bubble_sort(int arr[], int len, bool inc)
{
    for(int i{}; i < len; i++)
    {
        bool was_swap{false};
        for(int j{i}; j < len; j++)
        {
            printArr(arr,len);
            if (inc)
            {
                int mn{};
                if (arr[i] > arr[j])
                    {
                        mn = arr[j];
                        arr[j] = arr[i];
                        arr[i] = mn;
                        was_swap = true;
                    }
            }
            else {
                int mn{};
                if (arr[i] < arr[j])
                    {
                        mn = arr[j];
                        arr[j] = arr[i];
                        arr[i] = mn;
                        was_swap = true;
                    }
            }
        }
        if (!was_swap){
                break;
            }
    }
}