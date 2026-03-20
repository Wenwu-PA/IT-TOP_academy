class Point
{
    double x;
    double y;
public:
    Point(): Point{0, 0}
    {}
    Point(double xP, double yP): x{ xP }, y{ yP }
    {}
    void display() const;
    friend Point operator+(const Point& p1,const Point& p2);
    friend Point operator-(const Point& p);
};