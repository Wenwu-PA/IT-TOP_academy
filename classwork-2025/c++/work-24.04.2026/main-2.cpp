#include <iostream>

template<typename T>
void display(T value){
    std::cout << value << "\n";
}

template<typename T>
T sum(T value2,T value1){

    return value2 + value1;

}

struct Point
{
    int x;
    int y;

    Point operator+(Point p2){
        return {x + p2.x, y + p2.y};
    }
    friend std::ostream&  operator<<(std::ostream& out, Point p);
};

std::ostream& operator<<(std::ostream& out, Point p){
    out << "(" << p.x << "," << p.y << ")" << "\n";
    return out;
}

int main(){
    int n1{1};
    int n2{2};
    display(sum(n1,n2));

    double d1{1};
    double d2{2};
    display(sum(d1,d2));

    Point x{1,2};
    Point y{2,3};
    display(sum(x,y));



    return 0;
}