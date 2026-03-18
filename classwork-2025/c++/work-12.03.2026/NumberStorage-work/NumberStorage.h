#include <iostream>
#include <cstdlib>
#include <ctime>

class NumberStorage{
    private: 
        int* array;
        int n;
        static int numsum;
    public:
        NumberStorage(int nP):  array{new int[n]}, n{nP}
        {
            srand(time(nullptr));
            for(int i{};i<n;i++){
                array[i]= rand() % 10 + 1;
            }
            int size = n*sizeof(int);
            numsum += size;
            std::cout << "add: " << size << " " << "total: " << numsum << '\n';
        }
        void print(){
            for (int i{};i < n;i++){
                std::cout << array[i] << ' ';
            }
            std::cout << "\n";

        }
        int getUsedMemory(){
            return numsum;
        }
        ~NumberStorage()
        {
            delete[] array;
            int size(n*sizeof(int));
            size -= numsum;
            std::cout << "free: " << size << " " << "total: " << numsum << "\n";
        }
};

int NumberStorage::numsum;