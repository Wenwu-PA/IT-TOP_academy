class Point
{
    int x;
    int y;
public:
    Point() = default;
    Point(int valX, int valY): x{valX}, y{valY}
    {}
    Point& setX(double value) = delete;
    Point& setX(int value){
        x = value;
        return *this;
    };
    Point& setY(double value) = delete;
    Point& setY(int value){
        y = value;
        return *this;
    };
    void show(){
        std::cout << x << ", " << y << '\n';
    };
};