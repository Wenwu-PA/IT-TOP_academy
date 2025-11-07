#include <iostream>

int max(int numA,int numB){
    if(numA > numB){
        return numA;
    }
    else{
        return numB;
    }

}
int min(int numA,int numB){
    if(numA < numB){
        return numA;
    }
    else{
        return numB;
    }

}

int pow(int numA,int numB){
    int res{1};
    for (int i{1}; i < numB; i++){
        res *= numA;
    }

    return res;
}

void main(){
    int output{};
    int input1{};
    int input2{};

    do{
        std::cout << "<start menu>" << '\n';

        std::cout << "input two numbers: " << "\n";
        std::cin >> input1 >> input2 ;

        std::cout << "1 - min" << '\n' << "2 - max" << '\n' << "3 - pow" << '\n' << "0 - break" << '\n';
        std::cin >> output;

        switch (output)
        {
        case 1:
            std::cout << "min number - " << min(input1,input2) << "\n";
            break;
        case 2:
            std::cout << "max number - " << max(input1,input2) << "\n";
            break;
        case 3:
            std::cout << "pow number - " << pow(input1,input2) << "\n";
            break;
        default:
        std::cout << "what?";
            break;
        }

    }while(output != 0); 
 
}