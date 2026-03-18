#pragma once
#include <string>

class Soundex {

public:
    std::string encode(const std::string& word) const;
private:
    std::string zeroPad(const std::string& word) const;
    std::string head(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
<<<<<<< HEAD
    std::string encodedDigit(char letter) const;
=======
    std::string encodedDigit() const;
>>>>>>> 1dc0a808a80ef6166f2ea5ef19760b787b0bd7ac
};