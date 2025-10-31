#include <iostream>

int main(){
    const int rowCount{9};
    const int columnCount{9};

    int arr[rowCount][columnCount]{
        {5,4,3,2,1,3,4,5},
        {6,6,6,6,6,6,6,6},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {6,6,6,6,6,6,6,6},
        {5,4,3,2,1,3,4,5},
    };

    for (int r{};r<rowCount;r++){
        for (int i{0}; i < columnCount-1; i++)
        {
            std::cout << arr[r][i] << " ";
        }
        std::cout << "\n";
        
    }

  return 0;
}