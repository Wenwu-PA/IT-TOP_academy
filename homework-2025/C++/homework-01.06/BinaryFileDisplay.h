#ifndef BINARYDISPLAY_H
#define BINARYDISPLAY_H

#include "FileDisplay.h"

class BinaryFileDisplay : public FileDisplay {
public:
    void Display(const char* path) override;
};

#endif