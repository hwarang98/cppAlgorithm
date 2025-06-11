#include <string>
#include <vector>
#include <iostream>
#include <map> 

using namespace std;

int solution(string s) {
    map<string, string> words_to_digits;
    words_to_digits["zero"] = "0";
    words_to_digits["one"] = "1";
    words_to_digits["two"] = "2";
    words_to_digits["three"] = "3";
    words_to_digits["four"] = "4";
    words_to_digits["five"] = "5";
    words_to_digits["six"] = "6";
    words_to_digits["seven"] = "7";
    words_to_digits["eight"] = "8";
    words_to_digits["nine"] = "9";

    for(auto const& [word, num]: words_to_digits){
        size_t index = s.find(word);
        while(index != string::npos){
            s.replace(index, word.length(), num);
            index = s.find(word, index + num.length());
        }
    }
    
    return stoi(s);

}
