#ifndef FILEDISPLAY_H
#define FILEDISPLAY_H

class FileDisplay {
public:
    virtual ~FileDisplay() {}
    virtual void Display(const char* path);
};

#endif