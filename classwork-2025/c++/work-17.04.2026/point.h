class Point3D;

class Point{
    int x;
    int y;
public:
    Point() = default;
    Point(int pX,int pY): x{pX}, y{pY}
    {}
    Point& setX(int pX){x = pX; return *this;}
    Point& setY(int pY){y = pY; return *this;}

    void show() const{
        std::cout << x << " "<< y << "\n";
    }
    operator bool() const
    {
        return x && y;
    }
    explicit operator Point3D() const;
};

class Point3D{
    int x;
    int y;
    int z;
public:
    Point3D() = default;
    Point3D(int pX, int pY,int pZ): x{pX},y{pY},z{pZ}
    {}
    Point3D& setX(int pX){x = pX; return *this;}
    Point3D& setY(int pY){y = pY; return *this;}
    Point3D& setZ(int pZ){z = pZ; return *this;}
    void show() const{
        std::cout << x << " "<< y << " "<<  z << "\n";
    }

    explicit operator bool() const
    {
        return x || y || z;
    }
    explicit operator Point() const;
};

Point::operator Point3D() const{
    return Point3D{x,y,0};
};
Point3D::operator Point() const{
    return Point{x,y};
};