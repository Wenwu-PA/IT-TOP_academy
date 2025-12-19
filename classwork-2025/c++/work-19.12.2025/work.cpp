#include <iostream>
#include <ctime>
#include <cstdlib>

void fillrand(int arr[],int len);
void printArr(int** arr, int nrows, int ncols);

int main()
{
    std::cout << "Введите количество студентов: " << '\n';
    int nstuds{};
    std::cin >> nstuds;
    std::cout << "Введите количество оценок: " << '\n';
    int nmarks{};
    std::cin >> nmarks;

    int** marks{ new int*[nstuds] };

    for (int i{}; i < nstuds; i++)
    {
        marks[i] = new int[nmarks];
        fillrand(marks[i],nmarks);
        
    }
    printArr(marks,nstuds,nmarks);

    for (int i{}; i < nstuds; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}
void fillrand(int arr[],int len){
    std::srand(std::time(nullptr));
    for (int i{};i < len;i++){
        arr[i]=rand();
    }
}
void printArr(int** arr, int nrows, int ncols)
{
    for (int i{}; i < nrows; i++)
    {
        for (int j{}; j < ncols; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}