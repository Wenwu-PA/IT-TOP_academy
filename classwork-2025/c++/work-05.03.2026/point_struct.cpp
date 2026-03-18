#include <iostream>

class Point{
    int x;
    int y;
    public:
        Point(int xP, int yP): x{xP}, y{yP}{}
        void print()
        {
            std::cout << x << " " << y;
        };
};

int main(){

    Point point{5,20};
    std::cout << "Point on source:" << '\n';
    point.print();

    return 0;
}