#include <iostream>

class NoSequence{
    bool init;
    int prevEl;
public:
    NoSequence(): init{false}, prevEl{0}
    {}
    bool operator()(int el)
    {
        if(init){
            bool result{prevEl != el};
            if(result){
                prevEl = el;
            }
            return result;
        }
        init = true;
        prevEl = el;
        return true;
    }
};

template<typename T>
void print(T* begin,T* end, char delimiter = ' ') 
{
    while(begin != end){
        std::cout << *begin++ << delimiter;
    }
    std::cout << "\n";
}

template<typename T, typename Predicate>
int copy_if(T* begin,T* end,T* beginD,T* endD, Predicate pred){
    int count{};
    while(begin != end && beginD != endD){
        if(pred(*begin)){
            *beginD = *begin;
            count++;
        }
        begin++;
    }
    return count;

}



bool odd(const int el){
    return el % 2 != 0;
}
bool even(const int el){
    return el % 2 == 0;
}

bool all(const int el){
    return true;
}





class SumLimit{
    int sumLimit;
    int sum;
public:
    SumLimit(int sL, int startSum): sumLimit{sL}, sum{startSum}
    {}
    SumLimit(int sL): SumLimit(sL,0)
    {}
    bool operator()(int el)
    {
        if (sum + el < sumLimit){
            sum +=el;
            return true;
        }
        return false;
    }
};

int main(){

    NoSequence noseq;


    const int ARRSIZE{5};
    int array[ARRSIZE]{1,2,3,4,5};
    print(array,array+ARRSIZE);
    
    int array2[ARRSIZE]{3,4,3,4,5};
    print(array2,array2+ARRSIZE);

    int n{copy_if(array,array+ARRSIZE,array2,array2+ARRSIZE,odd)};
    int n2{copy_if(array,array+ARRSIZE,array2,array2+ARRSIZE,even)};
    int n3{copy_if(array,array+ARRSIZE,array2,array2+ARRSIZE,all)};

    std::cout << n << "\n";
    std::cout << n2 << "\n";
    std::cout << n3 << "\n";
    



    return 0;
}