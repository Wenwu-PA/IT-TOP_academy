#include <iostream>

int main(){
  double aver {};
  int arr[6]{1,2,-5,4,-15,6};
  for (int i{0}; i <= 5; ++i)
    {
        std::cout << "arr - " << i << "\n" << "element - " << arr[i] << "\n";
        aver += arr[i];
        if (arr[i] < 0)
        {
          aver += arr[i];
        }
    }
    std::cout << aver << "\n";
    std::cout << "\n";

    return 0;
}
