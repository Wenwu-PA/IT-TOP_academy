#ifndef ASCIIDISPLAY_H
#define ASCIIDISPLAY_H

#include "FileDisplay.h"

class AsciiFileDisplay : public FileDisplay {
public:
    void Display(const char* path) override;
};

#endif