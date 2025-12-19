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

void print_arr(int** arr, int nrows, int ncols)
{
    for (int i{}; i < nrows; i++)
    {
        int rowlen{ (i+1 > ncols) ? ncols : i + 1 };
        for (int j{}; j < rowlen; j++)
        {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    std::srand(std::time(nullptr));

    std::cout << "Введите количество студентов: ";
    int nstuds{};
    std::cin >> nstuds;
    std::cout << "Введите количество оценок: ";
    int nmarks{};
    std::cin >> nmarks;

    // создание массива указателей на строки
    int** marks{ new int*[nstuds] };
    for (int i{}; i < nstuds; i++)
    {
        int len{(i+1 > nmarks) ? nmarks : i + 1 };
        // выделение памяти под строку массива
        marks[i] = new int[len];
        // заполнение строки массива случайными оценками от 1 до 5
        fill_arr(marks[i], len);
    }
    print_arr (marks,nstuds,nmarks);

    for (int i{}; i < nstuds; i++)
    {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}