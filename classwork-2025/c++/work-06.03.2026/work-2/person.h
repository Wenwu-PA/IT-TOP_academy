#include <cstring>

class Person{
    int id;
    int age;
    char* name;
public: 
    Person()
        : Person{nullptr,0,0}
    {}
    Person(const char* nameP,int ageP) 
        : Person{nameP,ageP,0}
    {}
    Person(const char* nameP,int ageP,int idP) 
        : age{ageP}, name{ nameP ? new char[strlen(nameP)+1] : nullptr},  id{idP}
    {
        if (name){
            strcpy(name,nameP);
        }
    }
    
    void print(){
        if (name){
            std::cout << "Name: " << name << "\nAge: " << age << "\nID: "<< id << '\n';  
        }
        else  std::cout << "Name: nothing" << "\nAge: " << age << "\nID: "<< id << '\n';  
    }

    ~Person(){
        delete []name;
    }
};