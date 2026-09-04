#ifndef HEXDISPLAY_H
#define HEXDISPLAY_H

#include "FileDisplay.h"

class HexFileDisplay : public FileDisplay {
public:
    void Display(const char* path) override;
};

#endif