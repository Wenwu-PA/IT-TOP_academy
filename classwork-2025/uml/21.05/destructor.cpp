#include <iostream>
#include <cstring>

class Base
{
    int size;
    char* str;
public:
    Base(int sz, const char* s): size{sz}, str(new char[sz])
    {strcpy(str,s);}


   virtual ~Base()
    {   std::cout << "Destrucotr worked" << "\n";
        delete[] str;
    }
};

class Derivered: public Base
{
    char* str2;
    int size2;
public: 
    Derivered(int sz1,const char* s1,
    const char* s2,int sz2): 
    Base{sz1,s1}, size2{sz2}, str2{new char[sz2]}
    {strcpy(str2,s2);}

    virtual ~Derivered()
    {
        std::cout << "Destructor\n";
        delete[] str2;
    }
};



int main(){
    Derivered* pDerivered;
    pDerivered = new Derivered{7,"Test","test-2",5};
    delete pDerivered;

    return 0;
}