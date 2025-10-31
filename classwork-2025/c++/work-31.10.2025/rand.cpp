#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
  const int num{100};
  int arr[num]{};
  std::srand(std::time({nullptr}));
  
  int rborder{};
  int lborder{};
  std::cout << "Border: ";
  std::cin >> lborder >> rborder;


  for (int i{0};i < num;i++){
  arr[i] = std::rand() % (rborder - lborder + 1) + lborder;
  }
  
  for(int i{}; i < num; i++){
  std::cout << arr[i] << " ";
  }

  return 0;
}
