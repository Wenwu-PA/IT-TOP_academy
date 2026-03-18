#include "soundex.h"

std::string Soundex::encode(const std::string& word) const{
    // std::string encoded(word.substr(0,1));
    // if(word.length()>1)
    //     encoded += '1';
    return zeroPad(head(word) + encodedDigits(word));
}
std::string Soundex::zeroPad(const std::string& word) const{
    auto serosNeeded{4 - word.length()};
    return word + std::string(serosNeeded,'0');
}
std::string Soundex::head(const std::string& word) const{
    return word.substr(0,1);
}
std::string Soundex::encodedDigits(const std::string& word) const{
    if(word.length()>1) return encodedDigit(word[1]);
    return "";
}
std::string Soundex::encodedDigit(char letter) const{
    return "1";
}