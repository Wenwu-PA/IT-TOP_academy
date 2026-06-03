#include <iostream>

class Employer{
protected:
    int id;
    std::string name;
public:
    virtual void print()=0;
}

class President : public Employer{

    std::string exp;
public:
    void print(){
        Employer::print(){
        std::cout << "Functin print accept\n";
        }
    }
};

class Manager : public Employer{
    virtual void print(){
            std::cout << "Manager information\n";
        }
};

class Worker : public Employer{

    virtual void print(){
        std::cout << "Worker information\n";
    }

};

int main(){
    const int numEmps{3};
    Employer* emps[numEmps]{
        new President{},
        new Manager{},
        new Worker{}
    }

    for (int i{}; i< numEmps;i++){
        emps[i] ->print();
    }

    return 0;
}