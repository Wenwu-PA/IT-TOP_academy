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
std::string Soundex::tail(const std::string& word) const{
    return word.substr(1);
}

std::string Soundex::encodedDigits(const std::string& word) const{
    std::string encoding;
    for(char letter: word){
        if(isComplete(encoding)) break;
        encoding += encodedDigit(letter);
    } 
    return encoding;
}
bool Soundex::isComplete(const std::string& encoding) const{
    return encoding.length() == MaxCodeLength - 1;
}
std::string Soundex::encodedDigit(char letter) const{
    const std::unordered_map<char,std::string> encodings
    {
        {'b',"1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
        {'c',"2"}, {'g',"2"}, {'j',"2"}, {'k',"2"}, {'q',"2"},
                   {'s',"2"}, {'x',"2"}, {'z',"2"},
        {'d',"3"}, {'t',"3"}, 
    };
    auto it = encodings.find(letter);
    return it == encodings.end() ? "" : it ->second;
}