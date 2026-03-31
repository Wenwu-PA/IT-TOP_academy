#pragma once

#include <string>
#include <unordered_map>
#include <cctype>

const size_t maxCodeLength{4};
const std::string NotADigit{"*"};
/// данный класс требуется для зашифрования <c>слова в цифры</c>
class Soundex
{
public:
    std::string encode(const std::string& word) const;
    std::string encodedDigit(char letter) const;

private:
    char lower(char c) const;
    std::string upperFront(const std::string& word) const;
    std::string head(const std::string& word) const;
    std::string tail(const std::string& word) const;
    std::string zeroPad(const std::string& word) const;
    std::string encodedDigits(const std::string& word) const;
    void encodeHead(std::string& encoding, const std::string& word) const;
    void encodeTail(std::string& encoding, const std::string& word) const;
    void encodeLetter(std::string& encoding, char letter, char lastLetter) const;
    bool isVowel(char letter) const;
    std::string lastDigit(const std::string& encoding) const;
    bool isComplete(const std::string& encoding) const;
};