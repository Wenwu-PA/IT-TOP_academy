#include "NumberStorage.h"
#include <iostream>

int main(){

    NumberStorage ns{25};
    NumberStorage ns2{20};
    NumberStorage ns3{15};
    NumberStorage ns4{10};
    ns.print();
    std::cout << ns2.getUsedMemory() << '\n';

}