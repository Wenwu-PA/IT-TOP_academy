#include <iostream>

int factRecurs(int n){
    if(n == 1  || n == 0){
        return 1;
    }
    else{
        return n * factRecurs(n - 1);
    }
}

int factIter(int n){

    int result{1};
    for (int i{ 1 }; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    int N{};
    std::cout << "Input N fact: ";
    std::cin >> N;
    std::cout << factRecurs(N) << "\n";
    std::cout << factIter(N);

    return 0;


}