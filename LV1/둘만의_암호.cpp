#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    unordered_set<char> skipSet(skip.begin(), skip.end());
    vector<char> validLetters;
    
    for(char i = 'a'; i <= 'z'; ++i){
        if(skipSet.find(i) == skipSet.end())
        {
            validLetters.push_back(i);
        }
    }


    for (const char& ch : s) {
        auto it = find(validLetters.begin(), validLetters.end(), ch);
        int findIndex = distance(validLetters.begin(), it);

        int newPos = (findIndex + index) % validLetters.size();
        answer += validLetters[newPos];
    }

    
    return answer;
}
