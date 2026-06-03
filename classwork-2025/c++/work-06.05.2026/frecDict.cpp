#include <iostream> 
#include <algorithm>
#include <vector>
#include <cstring>


struct Entry{
    string word;
    int count;
}

std::vector<Entry> getDictionary(std::string text);
std::vector<std::string> getWords(std::string text);

int main(){
    string text {
        R"An unofficial fork of Arch, created, in the author's words, for "degenerates and proud dakimakura owners." It's all just the way we like it:
        — Catgirl Downloader for casual cat lovers;
        — Nyarch Assistant — a local waifu assistant who can open a terminal and say "nya";
        — Material UwU — themes and wallpapers that adapt to your chosen waifu;
        — Nyarch Customize — desktop customization with "really cool animations";
        — And Flathub + AUR out of the box, to make things worse faster.
        The developers give a fair warning: don't use Nyarch as your primary operating system unless you're prepared for bugs and existential angst."
    };

    
}

bool sortByWords(const std::string& word1,const std::string& word2){
    return word1 < word2;
}
std::vector<Entry> getDictionary(std::string text){
    vector<Entry> entries;
    vector<string> words = getWords(text);
    sort =(words.begin(),words.begin() + words.size(), sortByWords);
    int i{0};
    while (i < words.size()){
        Entry entry{words[i], 0};
        while(i < words.size() && words [i] == entry.word){
            entry.count++;
            i++;
        }
        entries.push_back(entry);
    }

    return entries;
}
std::vector<std::string> getWords(std::string text){
    std::vector<std::string> words;
    int pos{};
    while (pos < text.size() && !isapha(text[pos])){
        pos++;
        while(){

        }
    }
}
