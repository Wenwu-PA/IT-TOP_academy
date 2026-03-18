class Point{

private:

public:
    int x;
    int y;
    static double PI;
    Point(int xP,int yP): x{xP}, y{yP}
    {}
    void print(){
        std::cout << x << " " << y << " " << PI << '\n';
    }

};

double Point::PI{3.14};