#pragma once
#include <string>
#include <unordered_map>

const size_t MaxCodeLength{4};

class Soundex {

public:
    std::string encode(const std::string& word) const;
private:
    std::string zeroPad(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string head(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
    std::string encodedDigit(char letter) const;
    bool isComplete(const std::string& word) const;
};