#include <iostream>

int main() {
    int M, N;
    
    std::cout << "Введите размер массива A: ";
    std::cin >> M;
    std::cout << "Введите размер массива B: ";
    std::cin >> N;
    
    int A[M], B[N];
    
    std::cout << "\nВведите элементы массива A:\n";
    for (int i = 0; i < M; i++) {
        std::cout << "A[" << i << "] = ";
        std::cin >> A[i];
    }
    
    std::cout << "\nВведите элементы массива B:\n";
    for (int i = 0; i < N; i++) {
        std::cout << "B[" << i << "] = ";
        std::cin >> B[i];
    }
    
    int C[M];
    int k = 0;
    
    for (int i = 0; i < M; i++) {
        bool foundInB = false;
        
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                foundInB = true;
                break;
            }
        }
        
        if (!foundInB) {
            bool alreadyInC = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == A[i]) {
                    alreadyInC = true;
                    break;
                }
            }
            
            if (!alreadyInC) {
                C[k] = A[i];
                k++;
            }
        }
    }
    
    std::cout << "\nМассив A: ";
    for (int i = 0; i < M; i++) {
        std::cout << A[i] << " ";
    }
    
    std::cout << "\nМассив B: ";
    for (int i = 0; i < N; i++) {
        std::cout << B[i] << " ";
    }
    
    std::cout << "\n\nРезультирующий массив C (элементы A, которых нет в B):\n";
    if (k == 0) {
        std::cout << "Массив пуст (все элементы A есть в B)";
    } else {
        for (int i = 0; i < k; i++) {
            std::cout << C[i] << " ";
        }
        std::cout << "\nВсего элементов: " << k;
    }
    
    std::cout << std::endl;
    
    return 0;
}