#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;
    int length;
    static int objectCount;

public:
    String();
    String(int size);
    String(const char* input);
    String(const String& other);
    ~String();

    void input();
    void output() const;

    static int getObjectCount();
};

#endif