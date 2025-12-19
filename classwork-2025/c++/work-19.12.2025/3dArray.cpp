#include <iostream>
#include <cstdlib>
#include <ctime>

void fill_arr(int* arr, int len)
{
    for (int i{}; i < len; i++)
    {
        arr[i] = rand() % 5 + 1;
    }
}

int main(){
        std::srand(std::time(nullptr));

    std::cout << "Введите количество предметов: ";
    int nsubj{};
    std::cin >> nsubj;
    std::cout << "Введите количество студентов: ";
    int nstuds{};
    std::cin >> nstuds;
    std::cout << "Введите количество оценок: ";
    int nmarks{};
    std::cin >> nmarks;
    int** marks{ new int*[nstuds] };

    int*** subjects = new int**[nsubj];
    for (int i{}; i < nsubj; i++)
    {
        int** marks{ new int*[nstuds] };
        for (int i{}; i < nstuds; i++)
        {
            marks[i] = new int[nmarks];
            fill_arr(marks[i], nmarks);
        }
    }

}