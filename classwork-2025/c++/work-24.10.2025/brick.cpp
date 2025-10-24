#include <iostream>

int main(){
for (int i{0}; i < 10;i++){
    for (int m{0}; m < 10;m++){
        if ((i >= m) && (i + m >= 10 -1)){
            std::cout << "|===|";
        }
        else{
            std::cout << "     ";
        }
    }
    std::cout << "\n";
}

    for(int i{0}; i < 7;i++){
        for (int j{0}; j < 10;j++){
            std::cout << "|###|";
            if (j == 9){ 
                continue;
            }
        }
        
        std::cout << "\n";
        }

    

    return 0;
}