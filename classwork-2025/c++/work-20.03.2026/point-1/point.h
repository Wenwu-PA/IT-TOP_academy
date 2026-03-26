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
    void read();
    
    static bool isEqual(const Point& p1, const Point& p2);
    bool operator==(const Point& p2);
    
    static Point add(const Point& p1, const Point& p2);
    Point operator+(const Point& p2);
    
    static Point mult(const Point& p, double value);
    static double distance(const Point& p1, const Point& p2);
    static double length(const Point& p);
    double operator%(const Point& p2);
    double operator!();
};