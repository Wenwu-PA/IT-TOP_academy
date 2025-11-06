#include <iostream>

void hw(){
    std::cout << "hello world" << '\n';
}

void print(std::string a){
    std::cout << a << '\n';
}

void line(char a, int len){
    for (int i{1}; i < len;i++){
        std::cout << a;
    }
    std::cout << "\n";
}

int fact(int a){
    int fact{1};
    for (int i{2}; i <= a;i++){
        fact *= i;
    }

    return fact;
}

void brick(int width,int height){
    for (int i{}; i < height; i++){
        line('#',width);
    }
}
int main(){
    
    hw();
    print("hello string");
    std::cout << fact(5) << "\n";
    line('#',10);
    brick(10,10);

    return 0;
}
