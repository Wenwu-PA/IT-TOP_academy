#include <iostream>
#include "array-2.h"

int main()
{
    const int ROWS{3};
    const int COLUMNS{3};
    Array2Linear arr{ROWS, COLUMNS};

    int counter{1};
    for (int i{}; i < ROWS; i++)
    {
        for (int j{}; j < COLUMNS; j++)
        {
            // arr.data[i][j] = counter++;
            arr(i,j) = counter++;
            
        }
    }
    
    arr.print();


    arr.deleteColumn(1);

    std::cout << "\n";
    
    arr.print();
    
    std::cout << "\n";

    arr.addColumn(1,new int[3]{12,3,2});

    arr.print();
}