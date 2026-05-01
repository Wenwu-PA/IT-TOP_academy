#ifndef RESERVOIR_H
#define RESERVOIR_H

#include <iostream>
#include <cstring>

enum ReservoirType {
    SEA,
    LAKE,
    POND,
    POOL,
    RIVER
};

const char* typeToString(ReservoirType type);

class Reservoir {
private:
    char* name;
    ReservoirType type;
    double width;
    double length;
    double maxDepth;
    static int objectCount;

public:
    Reservoir();
    explicit Reservoir(const char* name);
    Reservoir(const char* name, ReservoirType type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    Reservoir& operator=(const Reservoir& other);

    const char* getName() const;
    ReservoirType getType() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    void setName(const char* name);
    void setType(ReservoirType type);
    void setWidth(double width);
    void setLength(double length);
    void setMaxDepth(double maxDepth);

    double calculateVolume() const;
    double calculateSurfaceArea() const;
    bool sameType(const Reservoir& other) const;
    bool compareSurfaceArea(const Reservoir& other) const;
    void copyFrom(const Reservoir& other);
    void display() const;
    void input();

    static int getObjectCount();
};

#endif