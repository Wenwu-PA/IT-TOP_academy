#include <iostream>
#include <limits>

int main(){
    const int rowCount{8};
    const int columnCount{8};
    
    int arr[rowCount][columnCount]{
        {5,4,3,2,1,3,4},
        {2,6,565,76,7,6,6},
        {0,2,0,78,0,68,0},
        {0,68,0,0,8,0,0},
        {0,3,0,234,9,0,0},
        {0,0,9,0,3,0,0},
        {6,23,1,0,0,79,0},
        {8,6,97,6,6,726,676},
    };

    for (int r{};r<rowCount;r++){
        int max{std::numeric_limits<int>::min()};
        for (int i{0}; i < columnCount; i++)
        {
            if (arr[i][r]>max){
                max = arr[r][i];
            }
        }
        std::cout << r+1 << "\t" << max << "\n";
        
    }

  return 0;
}