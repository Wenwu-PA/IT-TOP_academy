#include <iostream>

class A{
protected:
    int val;
public:
    A(): val{5}
    {}
};

class B: public virtual A
{};

class C: public virtual A
{};

class D: public B, public C
{
public:
    void printVal(){
        std::cout << &(val) << "\n";
    }
};

int main(){
    D d;
    B b;
    C c;
    d.printVal();

    std::cout << sizeof(c) << "\n";
    std::cout << sizeof(b) << "\n";

    std::cout << sizeof(d) << "\n";


    return 0;
}