#include <iostream>

int main(){
  const int lenArr{31};
  double border{};
  double temps[lenArr]{-5, -10 ,-2 ,-4 ,0 ,1 ,-3,- 12, -5, 2,-4,-4,-5,-2,-5,-1,-7,-8,-2,-3,-5,-4,-3,-4,-5,-6,-3,-4,-2,-3,-2};
  double aver{};
  double countLower{};
  
  std::cout << "input temp: " << "\n";
  std::cin >> border;

  for (int i{}; i < lenArr; ++i){
    aver += temps[i];
    if (temps[i] < border){
      countLower++;
    }
  }
  aver /= lenArr;

  std::cout << "average: " << aver << "\n";
  std::cout << "number of lower than border: " << countLower; 

  return 0;
}
