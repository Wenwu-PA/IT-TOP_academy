#include <iostream>
#include <cstdlib>
#include <ctime>

void fillWithRand(int arr[], int size);
void print3DArray(int** arr[], int tabs, int rows, int cols);

void fill_arr(int* arr, int len)
{
    for (int i{}; i < len; i++)
    {
        arr[i] = rand() % 5 + 1;
    }
}

int main(){
    std::srand(std::time(nullptr));
    int n1{};
    int n2{};
    int n3{};
    std::cout << "Enter amount of students: ";
    std::cin >> n1;
    std::cout << "Enter amount of marks: ";
    std::cin >> n2;
    std::cout << "Enter amount of marks: ";
    std::cin >> n3;

    int*** subjects{new int**[n1]};
    
    for(int i{}; i < n1; i++)
    {
        subjects[i] = {new int*[n2]};
        for (int j{}; j < n2; j++)
        {
            subjects[i][j] = new int[n3];
            fillWithRand(subjects[i][j], n3);
        }
    }
    print3DArray(subjects, n1, n2, n3);

}


void fillWithRand(int arr[], int size)
{
    for(int i{}; i < size; i++)
        arr[i] = std::rand() % 100 + 1;
}

void print3DArray(int** arr[], int tabs, int rows, int cols)
{
    for(int i{}; i < tabs; i++)
    {   
        for(int j{}; j < rows; j++)
        {
            for (int g{}; g < cols; g++)
            {
                std::cout << arr[i][j][g] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }       
}