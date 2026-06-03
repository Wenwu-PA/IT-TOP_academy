#include <iostream>
#include <cstring>

template<typename T>
T max(T v1,T v2){
    return (v1 > v2 ? v1 : v2);
}

template<>
const char* max<const char*>(const char* v1,const char* v2){
    return (std::strcmp(v1, v2) ? v1 : v2);
}

int main(){
    int i1{10};
    int i2{20};
    std::cout << max(i1,i2) << "\n";

    double d1{10.5};
    double d2{20.5};
    std::cout << max(d1,d2) << "\n";

    
    std::string s1{"hi"};
    std::string s2{"bye"};
    //std::cout << max(s1,s2) << '\n';

    const char* h1{"hi"};
    const char* h2{"bye"};
    std::cout << max(h1,h2) << '\n';
}