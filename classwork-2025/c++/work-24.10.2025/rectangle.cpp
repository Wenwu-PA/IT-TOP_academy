#include <iostream>

int main(){
    int width{};
    int hight{};
    char symbol1{};
    char symbol2{};
    char symbol3{};
    std::cout << "Введите высоту,ширину,символ 1 и символ 2 и символ 3: ";
    std::cin >> hight >> width >> symbol1 >> symbol2 >> symbol3;

    for (int i{1}; i < hight; i++){
        for(int j{1}; j <= width;j++){
            if(i == j){
                std::cout << symbol1 << " ";
            }
            else if(j + i == width + 1){
                std::cout << symbol3 << " ";
            }
            else if((i < j) && (i + j > width -1)){
                std::cout << " ";
            }
            else{
                std::cout << symbol2 << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}